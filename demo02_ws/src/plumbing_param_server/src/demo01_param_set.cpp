#include "ros/ros.h"


// 设置机器人的共享参数：类型、半径

int main(int argc, char *argv[])
{
    /* code */
    ros::init(argc, argv, "set_param_c");
    ros::NodeHandle nh;

    //参数新增
    //1.
    nh.setParam("type", "xiaohuang");
    nh.setParam("radius", 0.15);

    //2.
    ros::param::set("type_param", "xiaobai");
    ros::param::set("radius_param", 0.15);

    //参数修改
    //1.
    nh.setParam("radius", 0.2);
    //2.
    ros::param::set("radius_param", 0.76);
    return 0;
}
