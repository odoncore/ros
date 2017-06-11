#!/usr/bin/env python
from std_msgs.msg import String, Float64
from geometry_msgs.msg import PoseStamped, TwistStamped
from mavros_msgs.srv import SetMode
from mavros_msgs.msg import State
from ros_drone.srv import *
import rospy

def callback(req):
    print "req:", req
    # pub = rospy.Publisher('chatter', String, queue_size=10)
    pubX = rospy.Publisher('gps_X', Float64, queue_size=10)
    pubY = rospy.Publisher('gps_Y', Float64, queue_size=10)
    pubZ = rospy.Publisher('gps_Z', Float64, queue_size=10)
    # gps_data = [req.x, req.y, req.z]
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        # print "gps_data:", gps_data
        # pub.publish(gps_data)
	print ("while req:", req)
	pubX.publish(req.x);
	pubY.publish(req.y);
	pubZ.publish(req.z);
	print "published: (%f, %f, %f)" %(req.x, req.y, req.z)
	rate.sleep()

def talker():
    rospy.init_node('controller_node')
    serv = rospy.Service('gps_service', gps_service, callback)
    print "controller_node.py"
    rospy.spin()

if __name__ == '__main__':
    talker()
