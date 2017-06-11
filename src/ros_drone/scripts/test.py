#!/usr/bin/env python
from std_msgs.msg import String, Float64
from geometry_msgs.msg import PoseStamped, TwistStamped, Twist
from mavros_msgs.srv import SetMode
from mavros_msgs.msg import State
from ros_drone.srv import *
import rospy

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data)#.data)

def listener():
    rospy.init_node('test_node', anonymous=True)

    rospy.Subscriber('ros_drone/gps_X', Float64, callback)
    rospy.Subscriber('ros_drone/gps_Y', Float64, callback)
    rospy.Subscriber('ros_drone/gps_Z', Float64, callback)
    #rospy.Subscriber('gps_service', Float64, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
