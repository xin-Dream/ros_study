#include "ros/ros.h"
#include "std_msgs/String.h"


void doMsg(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("翠花获取的数据：%s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    /* code */
    ros::init(argc, argv, "cuihua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("fangzi", 10, doMsg);

    //回头函数
    ros::spin();

    return 0;
}
