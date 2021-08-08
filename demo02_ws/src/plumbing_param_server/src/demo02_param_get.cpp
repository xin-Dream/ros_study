#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    /* code */
    ros::init(argc, argv, "set_param_c");
    ros::NodeHandle nh;

    //参数查询
    double radius = nh.param("radius", 0.5);
    ROS_INFO("radius=%.2f", radius);

    //
    double radius2 = 0.0;
    bool result2 = nh.getParam("radius", radius2);
    if (result2)
    {
        ROS_INFO("获取半径是:%.2f", radius2);
    }else
    {
        ROS_INFO("获取半径不存在");
    }

    //性能有提升，差距不大
    double radius3 = 0;
    bool result3 = nh.getParamCached("radius", radius3);
    if (result3)
    {
        ROS_INFO("获取半径是:%.2f", radius3);
    }else
    {
        ROS_INFO("获取半径不存在");
    }

    //
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name:names){
        ROS_INFO("遍历元素为：%s", name.c_str());
    }

    //
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxx");
    ROS_INFO("radius存在吗? %d", flag1);
    ROS_INFO("radiusxx存在吗? %d", flag2);

    //
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("搜索结果:%s", key.c_str());

    return 0;
}
