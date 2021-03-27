
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//发布速度消息
/*
    发布速度消息
        话题turtel/cmd_vel
        消息geometry_msgs/Twist
*/


int main(int argc, char *argv[])
{
    //1.初始化ROS节点
    ros::init(argc,argv,"my_control");

    //2.创建节点句柄
    ros::NodeHandle nh;
    //3.创建发布对象
    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);
    //4.发布逻辑
    ros::Rate rate (10);
    //组织被发布的消息
    geometry_msgs::Twist twist;
    twist.linear.x=1.0;
    twist.linear.y=0.0;
    twist.linear.z=0.0;

    twist.angular.x=0.0;
    twist.angular.y=0.0;
    twist.angular.z=0.5;

    //循环发布
    while (ros::ok())
    {
        pub.publish(twist);

        rate.sleep();
        
        //5.spinone
        ros::spinOnce();

    }
   
    /* code */
    return 0;
}
