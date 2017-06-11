# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ros_drone: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iros_drone:/home/kimbowon/catkin_ws/src/ros_drone/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Imavros_msgs:/opt/ros/indigo/share/mavros_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Inav_msgs:/opt/ros/indigo/share/nav_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ros_drone_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv" NAME_WE)
add_custom_target(_ros_drone_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_drone" "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv" ""
)

get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg" NAME_WE)
add_custom_target(_ros_drone_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_drone" "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_drone
)

### Generating Services
_generate_srv_cpp(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_drone
)

### Generating Module File
_generate_module_cpp(ros_drone
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_drone
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ros_drone_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ros_drone_generate_messages ros_drone_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv" NAME_WE)
add_dependencies(ros_drone_generate_messages_cpp _ros_drone_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg" NAME_WE)
add_dependencies(ros_drone_generate_messages_cpp _ros_drone_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_drone_gencpp)
add_dependencies(ros_drone_gencpp ros_drone_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_drone_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_drone
)

### Generating Services
_generate_srv_lisp(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_drone
)

### Generating Module File
_generate_module_lisp(ros_drone
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_drone
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ros_drone_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ros_drone_generate_messages ros_drone_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv" NAME_WE)
add_dependencies(ros_drone_generate_messages_lisp _ros_drone_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg" NAME_WE)
add_dependencies(ros_drone_generate_messages_lisp _ros_drone_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_drone_genlisp)
add_dependencies(ros_drone_genlisp ros_drone_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_drone_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone
)

### Generating Services
_generate_srv_py(ros_drone
  "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone
)

### Generating Module File
_generate_module_py(ros_drone
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ros_drone_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ros_drone_generate_messages ros_drone_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/srv/gps_service.srv" NAME_WE)
add_dependencies(ros_drone_generate_messages_py _ros_drone_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimbowon/catkin_ws/src/ros_drone/msg/gps.msg" NAME_WE)
add_dependencies(ros_drone_generate_messages_py _ros_drone_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_drone_genpy)
add_dependencies(ros_drone_genpy ros_drone_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_drone_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_drone)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_drone
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(ros_drone_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ros_drone_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(ros_drone_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(ros_drone_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(ros_drone_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_drone)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ros_drone
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(ros_drone_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ros_drone_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(ros_drone_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(ros_drone_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(ros_drone_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_drone
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(ros_drone_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ros_drone_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(ros_drone_generate_messages_py mavros_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(ros_drone_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(ros_drone_generate_messages_py nav_msgs_generate_messages_py)
endif()
