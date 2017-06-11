#!/usr/bin/env python
from std_msgs.msg import String, Float64
from geometry_msgs.msg import PoseStamped, TwistStamped, Twist
from mavros_msgs.srv import SetMode
from mavros_msgs.msg import State
from ros_drone.srv import *
import rospy

def callbackX(data):
    rospy.loginfo(rospy.get_caller_id() + 'sub_X: %s', data)

def callbackY(data):
    rospy.loginfo(rospy.get_caller_id() + 'sub_Y: %s', data)

def callbackZ(data):
    rospy.loginfo(rospy.get_caller_id() + 'sub_Z: %s', data)

def sub_test():
    rospy.init_node('sub_test_node', anonymous=True)
    rospy.Subscriber('gps_X', Float64, callbackX)
    rospy.Subscriber('gps_Y', Float64, callbackY)
    rospy.Subscriber('gps_Z', Float64, callbackZ)
    rospy.spin()

if __name__ == '__main__':
    sub_test()
