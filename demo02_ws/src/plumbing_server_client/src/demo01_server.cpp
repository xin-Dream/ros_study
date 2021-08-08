#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNums(plumbing_server_client::AddInts::Request &requst,
plumbing_server_client::AddInts::Response &response){

    //请求
    int num1 = requst.num1;
    int num2 = requst.num2;
    ROS_INFO("解析出的数字为：num1=%d，num2=%d", num1, num2);

    //响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和结果sum=%d", sum);

    return true;
}

int main(int argc, char *argv[])
{

    setlocale(LC_ALL, "");

    ros::init(argc, argv, "wuye");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("addInts", doNums);
    
    ROS_INFO("服务器端启动");

    ros::spin();

    return 0;
}
