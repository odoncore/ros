/*
 * mansoo_offboard_node.cpp
 *
 *  Created on: 2016. 7. 26.
 *      Author: mansoo
 */

#include<iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

mavros_msgs::State              g_current_state;
geometry_msgs::PoseStamped     g_pose;

void cbState(const mavros_msgs::State::ConstPtr& msg)
{
    g_current_state = *msg;

    std::cout << "\n[MANSOO] state_cb(), -----------";
    std::cout << "\n          g_current_state.connected = " << ((g_current_state.connected) ? "OK!" : "Not yet!");
    std::cout << "\n          g_current_state.armed = " << ((g_current_state.armed ) ? "OK!" : "Not yet!");
    std::cout << "\n          g_current_state.guided = " << ((g_current_state.guided) ? "OK!" : "Not yet!");
    std::cout << "\n          g_current_state.mode = " << g_current_state.mode;
    std::cout << "\n          g_pose.pose.position.x = " << g_pose.pose.position.x;
    std::cout << "\n          g_pose.pose.position.y = " << g_pose.pose.position.y;
    std::cout << "\n          g_pose.pose.position.z = " << g_pose.pose.position.z;
    std::cout << "\n[MANSOO] ------------------------\n";
}

void cbMoveX(const std_msgs::String::ConstPtr& msg)
{
  std::string::size_type sz;   // alias of size_t

  int pos = std::stoi (msg->data, &sz);

  g_pose.pose.position.x = pos;
}

void cbMoveY(const std_msgs::String::ConstPtr& msg)
{
  std::string::size_type sz;   // alias of size_t

  int pos = std::stoi (msg->data, &sz);

  g_pose.pose.position.y = pos;
}

void cbMoveZ(const std_msgs::String::ConstPtr& msg)
{
  std::string::size_type sz;   // alias of size_t

  int pos = std::stoi (msg->data, &sz);

  g_pose.pose.position.z = pos;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mansoo_offboard_node");
    ros::NodeHandle nh;

    ros::Subscriber     state_sub        = nh.subscribe<mavros_msgs::State>("mavros/state", 10, cbState);

    ros::Subscriber     move_x_sub        = nh.subscribe("mansoo_drone/x_pos", 10, cbMoveX);
    ros::Subscriber     move_y_sub        = nh.subscribe("mansoo_drone/y_pos", 10, cbMoveY);
    ros::Subscriber     move_z_sub        = nh.subscribe("mansoo_drone/z_pos", 10, cbMoveZ);

    ros::Publisher      local_pos_pub    = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
    ros::ServiceClient  arming_client   = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    ros::ServiceClient  set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && g_current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    //  geometry_msgs::PoseStamped pose;
    g_pose.pose.position.x = 0;
    g_pose.pose.position.y = 0;
    g_pose.pose.position.z = 2;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i)
    {
        local_pos_pub.publish(g_pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

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
        else
        {
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
