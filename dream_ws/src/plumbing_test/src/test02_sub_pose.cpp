#include "ros/ros.h"
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("坐标: (%.2f,%.2f),朝向:(%.2f),线速度:(%.2f),角速度：(%.2f)",
    pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);



}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //1.init ROS node
    ros::init(argc,argv,"sub_pose");
    //2.setup node handle
    ros::NodeHandle nh;
    //3.setup node 
    ros::Subscriber sub=nh.subscribe("/turtle1/pose",100,doPose);
    //4.receive data(callback function)
    //5.spinonce
    ros::spin();
    //
    /* code */
    return 0;
}
