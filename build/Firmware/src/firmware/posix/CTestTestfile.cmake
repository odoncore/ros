# CMake generated Testfile for 
# Source directory: /home/wonsik/catkin_ws/src/Firmware/src/firmware/posix
# Build directory: /home/wonsik/catkin_ws/build/Firmware/src/firmware/posix
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(rcS_tests "/home/wonsik/catkin_ws/src/Firmware/Tools/sitl_run.sh" "/home/wonsik/catkin_ws/devel/lib/px4/px4" "posix-configs/SITL/init/test" "none" "none" "none" "/home/wonsik/catkin_ws/src/Firmware" "/home/wonsik/catkin_ws/build/Firmware")
set_tests_properties(rcS_tests PROPERTIES  PASS_REGULAR_EXPRESSION "All tests passed" WORKING_DIRECTORY "/home/wonsik/catkin_ws/build/Firmware/tmp")
