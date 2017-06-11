#!/usr/bin/env python

NAME = 'gps_server'

from ros_drone.srv import *
import rospy

def gps(req):
	print "req: ", req
	print "req: (%f, %f, %f)" %(req.x, req.y, req.z)	
	return [req.x, req.y, req.z]

def gps_server():
	rospy.init_node(NAME)
	serv = rospy.Service('gps_service', gps_service, gps)
	print "launched::gps_server"
	rospy.spin()

if __name__ == '__main__':
	gps_server()
