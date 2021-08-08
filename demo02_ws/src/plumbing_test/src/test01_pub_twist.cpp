#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

//发布速度消息

int main(int argc, char *argv[])
{

    ros::init(argc, argv, "mycontrol");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    ros::Rate rate(10);

    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;

    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.5;

    while (ros::ok)
    {
        pub.publish(twist);
        rate.sleep();
        ROS_INFO("runing");

        ros::spinOnce();
    }

    return 0;
}
