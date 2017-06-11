#!/usr/bin/env python

import sys
import rospy
from ros_drone.srv import *

def gps_client(x, y, z):
	rospy.wait_for_service('gps_service')
	try:
		gps = rospy.ServiceProxy('gps_service', gps_service)
		response = gps(x, y, z)
		print 'response:', response
		return response
	except rospy.ServiceException, e:
		print 'Error: %s' %e

def usage():
	return '%s [x y z]' %(sys.argv[0])

if __name__ == '__main__':
	if len(sys.argv) == 1:
		x = 0#random.randint(-10, 10)
		y = 0#random.randint(-10, 10)
		z = 0#random.randint(-10, 10)
	elif len(sys.argv) == 4:
		x = int(sys.argv[1])
		y = int(sys.argv[2])
		z = int(sys.argv[3])
	else:
		print usage()
		sys.exit(1)
	print 'Requesting (%f, %f, %f)' %(x, y, z)
