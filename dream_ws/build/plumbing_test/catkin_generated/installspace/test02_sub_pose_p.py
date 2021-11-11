#!/usr/bin/env python2

import rospy
from  turtlesim.msg import Pose


def doPose(pose):
    rospy.loginfo("P->info:location:(%.2f,%.2f),face:(%.2f),linear_velocity:(%.2f),angular_velocity:(%.2f)",pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)

if __name__ == "__main__":
    rospy.init_node("sub_pose_p")

    sub=rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=100)

    rospy.spin()