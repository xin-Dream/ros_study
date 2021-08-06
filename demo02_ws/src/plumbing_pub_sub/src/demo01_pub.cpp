#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "ergouzi");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fangzi", 10);

    //要求以10Hz的频率发布数据
    ros::Rate rate(1);

    std_msgs::String msg;

    int count = 0;

    while (ros::ok)
    {
        count++;
        // msg.data = "hello";

        std::stringstream ss;
        ss << "hello ---" << count;

        msg.data = ss.str();

        pub.publish(msg);

        ROS_INFO("发布的数据是：%s", ss.str().c_str());
        rate.sleep();

        ros::spinOnce();//回头一次
    }

    return 0;
}



