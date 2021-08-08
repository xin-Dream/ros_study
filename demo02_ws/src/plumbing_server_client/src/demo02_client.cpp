#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"


// 若先启动客户端，不抛出异常，挂起等待服务器启动
//

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    //获取输入的参数
    if (argc!=3)
    {
        ROS_INFO("提交的参数个数不对");
        return 1;
    }

    /* code */
    ros::init(argc, argv, "kehu");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");

    //判断服务器状态函数
    //1
    // client.waitForExistence();
    //2
    ros::service::waitForService("addInts");

    //组织请求
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    //处理响应
    bool flag = client.call(ai);

    if (flag)
    {
        ROS_INFO("处理结果为：%d", ai.response.sum);
    }else{
        ROS_INFO("处理失败");
    }

    return 0;
}
