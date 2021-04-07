#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
"""
    publish speed information
        rostopic:turtel/cmd_vel
        msgs:geometry_msgs/Twist
"""


if __name__ == "__main__":

    #1.init ros node
    rospy.init_node("my_control_p")

    #2.setup publisher
    pub=rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=1000)
    
    #3.publish data
    #set publish rate
    rate=rospy.Rate(10)

    #make information of speed
    twist=Twist()
    twist.linear.x=1.0
    twist.linear.y=0.0
    twist.linear.z=0.0

    twist.angular.x=0.0
    twist.angular.y=0.0
    twist.angular.z=0.5


    #start publish
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()

    pass
