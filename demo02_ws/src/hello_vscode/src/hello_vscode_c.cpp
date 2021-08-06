#include "ros/ros.h"

int main(int argc, char *argv[])
{

    //解决乱码问题
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "hello");

    ROS_INFO("nihao，哈哈哈");

    /* code */
    return 0;
}
