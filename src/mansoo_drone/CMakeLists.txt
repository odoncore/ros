cmake_minimum_required(VERSION 2.8.3)
project(mansoo_drone)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES modudculab_ros
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

set (CMAKE_CXX_STANDARD 11)

###########
## Build ##
###########

# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(
	offboard_node 
	src/offboard_node.cpp)

target_link_libraries(
	offboard_node 
	${catkin_LIBRARIES}
)

add_executable(
	controller_node 
	src/controller_node.cpp)

target_link_libraries(
	controller_node 
	${catkin_LIBRARIES}
)

#add_dependencies(
#	offboard_node
#	mansoo_drone_generate_messages_cpp
#)

