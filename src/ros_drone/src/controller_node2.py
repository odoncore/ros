#!/usr/bin/env python
from std_msgs.msg import String, Float64
from geometry_msgs.msg import PoseStamped, TwistStamped, Twist
from mavros_msgs.srv import SetMode
from mavros_msgs.msg import State
from ros_drone.srv import *
import rospy

def callbackX(data):
    rospy.loginfo(rospy.get_caller_id() + 'X: %s', data)
    pubX.publish(data)

def callbackY(data):
    rospy.loginfo(rospy.get_caller_id() + 'Y: %s', data)
    pubY.publish(data)

def callbackZ(data):
    rospy.loginfo(rospy.get_caller_id() + 'Z: %s', data)
    pubZ.publish(data)

def listener():
    rospy.init_node('controller_node2', anonymous=True)

    rospy.Subscriber('gps_serviceX', Float64, callbackX)
    rospy.Subscriber('gps_serviceY', Float64, callbackY)
    rospy.Subscriber('gps_serviceZ', Float64, callbackZ)

    global pubX, pubY, pubZ

    pubX = rospy.Publisher('gps_X', Float64, queue_size=10)
    pubY = rospy.Publisher('gps_Y', Float64, queue_size=10)
    pubZ = rospy.Publisher('gps_Z', Float64, queue_size=10)
    #pubX.publish(36.5555);

 #   rospy.Subscriber('gps_serviceX', Float64, callback)
  #  rospy.Subscriber('gps_serviceY', Float64, callback)
   # rospy.Subscriber('gps_serviceZ', Float64, callback)
    #rospy.Subscriber('gps_service', Float64, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()

#def gps_client(x, y, z):
#	rospy.wait_for_service('gps_service')
#	try:
#		gps = rospy.ServiceProxy('gps_service', gps_service)
#		response = gps(x, y, z)
#		pubX.publish(x)
#		pubY.publish(y)
#		pubZ.publish(z)
#		print 'response:', response
#		return response
#	except rospy.ServiceException, e:
#		print 'Error: %s' %e

#def usage():
#	return '%s [x y z]' %(sys.argv[0])

#if __name__ == '__main__':
#	rospy.init_node('controller_node2')
#	if len(sys.argv) == 1:
#		x = 0
#		y = 0
#		z = 0
#	elif len(sys.argv) == 4:
#		x = float(sys.argv[1])
#		y = float(sys.argv[2])
#		z = float(sys.argv[3])
#	else:
#		print usage()
#		sys.exit(1)
#	global pubX, pubY, pubZ
#	pubX = rospy.Publisher('gps_X', Float64, queue_size=10)
#	pubY = rospy.Publisher('gps_Y', Float64, queue_size=10)
#	pubZ = rospy.Publisher('gps_Z', Float64, queue_size=10)
#	while True:
#		print gps_client(x, y, z)
	# print 'Requesting (%f, %f, %f): %s' %(x, y, z, gps_client(x, y, z))

#def callback(req):
#    print "req:", req
#    pubX.publish(req.x)
#    pubY.publish(req.y)
#    pubZ.publish(req.z)
#    print "published: (%f, %f, %f)" %(req.x, req.y, req.z)
#    return [req.x, req.y, req.z]


#def talker():
#    rospy.init_node('controller_node2')
#    serv = rospy.Service('gps_service', gps_service, callback)
#    global pubX, pubY, pubZ
#    pubX = rospy.Publisher('gps_X', Float64, queue_size=10)
#    pubY = rospy.Publisher('gps_Y', Float64, queue_size=10)
#    pubZ = rospy.Publisher('gps_Z', Float64, queue_size=10)
#    print "controller_node2.py"
#    rospy.spin()

#if __name__ == '__main__':
#    talker()
