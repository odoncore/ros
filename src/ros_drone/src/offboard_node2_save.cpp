#include<iostream>
#include <cstdio>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/PoseStamped.h>
//#include <geometry_msgs/PoseWithCovarianceStamped.h>
//#include <nav_msgs/Odometry.h>
#include <mavros_msgs/GlobalPositionTarget.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <sensor_msgs/NavSatFix.h>

mavros_msgs::State              g_current_state;
geometry_msgs::PoseStamped     g_pose;
ros::Publisher local_pos_pub;

double original_latitude = 0.0;
double original_longitude = 0.0;
double original_altitude = 0.0;
bool original_flag = false;
bool zFlag = false;

void cbState(const mavros_msgs::State::ConstPtr& msg);
void cbMoveX(const std_msgs::Float64::ConstPtr& msg);
void cbMoveY(const std_msgs::Float64::ConstPtr& msg);
void cbMoveZ(const std_msgs::Float64::ConstPtr& msg);
void callbackGlobal(const sensor_msgs::NavSatFix::ConstPtr& gps);
//void callbackLocal(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& gps);
//void callbackLocal(const nav_msgs::Odometry::ConstPtr& gps);
voic callbackLocal(const mavros_msgs::GlobalPositionTarget::ConstPtr& gps);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offboard_node");
    ros::NodeHandle nodeHandle;

    ros::Subscriber state_sub = nodeHandle.subscribe<mavros_msgs::State>("mavros/state", 10, cbState);
    ros::Subscriber global_position = nodeHandle.subscribe<sensor_msgs::NavSatFix>("mavros/global_position/global", 10, callbackGlobal);
    // ros::Subscriber local_position = nodeHandle.subscribe<geometry_msgs::PoseWithCovarianceStamped>("mavros/global_position/local", 10, callbackLocal);
    // ros::Subscriber local_position = nodeHandle.subscribe<nav_msgs::Odometry>("mavros/global_position/local", 10, callbackLocal);
    ros::Subscriber local_position = nodeHandle.subscribe<mavros_msgs::GlobalPositionTarget>("mavros/setpoint_raw/global", 10, callbackLocal);
    ros::Subscriber gpsX_sub = nodeHandle.subscribe<std_msgs::Float64>("gps_serviceX", 10, cbMoveX);
    ros::Subscriber gpsY_sub = nodeHandle.subscribe<std_msgs::Float64>("gps_serviceY", 10, cbMoveY);
    ros::Subscriber gpsZ_sub = nodeHandle.subscribe<std_msgs::Float64>("gps_serviceZ", 10, cbMoveZ);

    /*ros::Publisher      */local_pos_pub    = nodeHandle.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
    ros::ServiceClient  arming_client   = nodeHandle.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    ros::ServiceClient  set_mode_client = nodeHandle.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && g_current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    //  geometry_msgs::PoseStamped pose;
   // g_pose.pose.position.x = 0;
   // g_pose.pose.position.y = 0;
   // g_pose.pose.position.z = 2;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i)
    {
        local_pos_pub.publish(g_pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";
    //offb_set_mode.request.custom_mode = "MANUAL";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    bool flag = false;    

    while(ros::ok())
    {


        if( g_current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0)))
        {
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.success)
            {
                ROS_INFO("Offboard enabled");
            }

            last_request = ros::Time::now();
        }
	//else if (g_current_state.mode == "MANUAL" && flag) { break; }
        else
        {
	  //  flag = true;
            if( !g_current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0)))
            {
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success)
                {
                    ROS_INFO("Vehicle armed");
                }

                last_request = ros::Time::now();
            }
        }


        local_pos_pub.publish(g_pose);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

void cbState(const mavros_msgs::State::ConstPtr& msg)
{
    g_current_state = *msg;

    std::cout << "\n[NALD] state_cb(), -----------";
    std::cout << "\n       g_current_state.connected = " << ((g_current_state.connected) ? "OK!" : "Not yet!");
    std::cout << "\n       g_current_state.armed = " << ((g_current_state.armed ) ? "OK!" : "Not yet!");
    std::cout << "\n       g_current_state.guided = " << ((g_current_state.guided) ? "OK!" : "Not yet!");
    std::cout << "\n       g_current_state.mode = " << g_current_state.mode;
    std::cout << "\n       g_pose.pose.position.x = " << g_pose.pose.position.x;
    std::cout << "\n       g_pose.pose.position.y = " << g_pose.pose.position.y;
    std::cout << "\n       g_pose.pose.position.z = " << g_pose.pose.position.z;
    std::cout << "\n[NALD] ------------------------\n";
}

void cbMoveX(const std_msgs::Float64::ConstPtr& msg)
{
  std::printf("msg->X: %.20lf\n", msg->data);
  g_pose.pose.position.x = (msg->data - original_latitude);// * 10e-5;
  std::printf("callbackX: %.20lf\n", g_pose.pose.position.x);
local_pos_pub.publish(g_pose);
  // std::cout << "callbackX: " << g_pose.pose.position.x << std::endl;
}

void cbMoveY(const std_msgs::Float64::ConstPtr& msg)
{
  std::printf("msg->Y: %.20lf\n", msg->data);
  g_pose.pose.position.y = (msg->data - original_longitude);// * 10e-5;
  std::printf("callbackY: %.20lf\n", g_pose.pose.position.y);
  local_pos_pub.publish(g_pose);
}

void cbMoveZ(const std_msgs::Float64::ConstPtr& msg)
{
  std::printf("msg->Z: %.20lf\n", msg->data);
  // g_pose.pose.position.z = msg->data;
  std::printf("callbackZ: %.20lf\n", g_pose.pose.position.z);
//local_pos_pub.publish(g_pose);
}

void callbackGlobal(const sensor_msgs::NavSatFix::ConstPtr& gps)
{
  if (!original_flag) {
    std::cout << "[GLOBAL -> ORIGINAL GPS SET]" << std::endl;
    original_flag = true;
    original_latitude = gps->latitude;
    original_longitude = gps->longitude;
    original_altitude = gps->altitude;
  }
  if (g_current_state.mode == "OFFBOARD" && !zFlag) {
      zFlag = true;
      g_pose.pose.position.z = original_altitude = gps->altitude;// * 10e-5;
      local_pos_pub.publish(g_pose);
  }
  std::cout << "[GLOBAL GPS] latitude: " << gps->latitude << std::endl;
  std::cout << "[GLOBAL GPS] longitude: " << gps->longitude << std::endl;
  std::cout << "[GLOBAL GPS] altitude: " << gps->altitude << std::endl;
  std::cout << "[ORIGIN GPS] latitude: " << original_latitude << std::endl;
  std::cout << "[ORIGIN GPS] longitude: " << original_longitude << std::endl;
  std::cout << "[ORIGIN GPS] altitude: " << original_altitude << std::endl;
}

// void callbackLocal(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& gps)
void callbackLocal(const nav_msgs::Odometry::ConstPtr& gps)
{
  std::cout << "[LOCALE GPS] latitude: " << gps->pose.pose.position.x << std::endl;
  std::cout << "[LOCALE GPS] longitude: " << gps->pose.pose.position.y << std::endl;
  std::cout << "[LOCALE GPS] altitude: " << gps->pose.pose.position.z << std::endl;
}
