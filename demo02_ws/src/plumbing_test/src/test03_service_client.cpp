#include "ros/ros.h"
#include "turtlesim/Spawn.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    /* code */
    ros::init(argc, argv, "touchGUI");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn spawn;

    spawn.request.x = 6.0;
    spawn.request.y = 5.0;
    spawn.request.theta = 3.0;
    spawn.request.name = "turtle4";

    //判断服务器状态
    client.waitForExistence();

    bool flag = client.call(spawn);

    if (flag)
    {
        ROS_INFO("响应成功");
        ROS_INFO("名称为：%s",spawn.response.name.c_str());
    }
    else{
        ROS_INFO("响应失败");
    }

    return 0;
}
