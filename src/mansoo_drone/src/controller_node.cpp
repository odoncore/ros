#include <iostream>
#include <string>

#include <chrono>
#include <thread>

#include <signal.h>

#include "ros/ros.h"
#include "std_msgs/String.h"

// Ctrl+C를 누르면 이 함수가 호출 됨
void cbSigintHandler(int sig)
{
  // node의 ros를 종료 함
  ros::shutdown();
}

std::vector<std::string> token_split(const std::string& s, char c)
{
    auto end = s.cend();
    auto start = end;

    std::vector<std::string> v;
    for( auto it = s.cbegin(); it != end; ++it ) {
        if( *it != c ) {
            if( start == end )
                start = it;
            continue;
        }
        if( start != end ) {
            v.emplace_back(start, it);
            start = end;
        }
    }
    if( start != end )
        v.emplace_back(start, end);
    return v;
}

int main(int argc, char **argv)
{
  std::string my_name = "controller_node";

  // All node must call this function to communicate with the roscore.
  ros::init(argc, argv, my_name);

  // ctrl+C를 눌렀을 때 프로그램을 종료하도록 이벤트 처리
  signal(SIGINT, cbSigintHandler);

  // 'chatter' 토픽에 대해 subscribe하고, publish 할 수 있도록 설정
  ros::NodeHandle n;

  ros::Publisher  pub_moveX = n.advertise<std_msgs::String>("mansoo_drone/x_pos", 10);
  ros::Publisher  pub_moveY = n.advertise<std_msgs::String>("mansoo_drone/y_pos", 10);
  ros::Publisher  pub_moveZ = n.advertise<std_msgs::String>("mansoo_drone/z_pos", 10);

  std_msgs::String pub_msg;  
 
  // 콘솔 입력할 때 ros로부터 수신되는 이벤트 처리가 안되기 때문에 ros의 이벤트 확인은 thread 처리로 변경
  std::thread t([]() {
     ros::AsyncSpinner spinner(1); // Use 4 threads
     spinner.start();
     ros::waitForShutdown();
  });

  while (ros::ok())
  {
      std::string in_msg;
      char ch;
      
      std::cout << "\n Drone Pos(X Y Z): ";

      while (ros::ok())
      {
        std::cin.get(ch); // blocking wait for standard input

        if (ch == '\n')
           break;

        in_msg += ch;
      }

      if (ch == '\n')
      {
        auto positions = token_split(in_msg, ' ');

        if (positions.size() == 3)
        {
          if (positions[0] != "-")
          {
            pub_msg.data = positions[0];        
            pub_moveX.publish(pub_msg);
          }

          if (positions[1] != "-")
          {
            pub_msg.data = positions[1];        
            pub_moveY.publish(pub_msg);
          }

          if (positions[2] != "-")
          {
            pub_msg.data = positions[2];        
            pub_moveZ.publish(pub_msg);
          }
        }
      }
    }

  ros::shutdown();

  t.join();

  return 0;
}
