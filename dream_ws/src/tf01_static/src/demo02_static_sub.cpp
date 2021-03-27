#include "ros/ros.h"

#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/*
    需求：订阅两个坐标系间的相对关系
*/


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");

    //初始化节点
    ros::init(argc,argv,"static_sub");

    //设置句柄
    ros::NodeHandle nh;

    //创建发布对象
    tf2_ros::Buffer buffer;                         //创建一个buffer缓存
    tf2_ros::TransformListener listener(buffer);    //创建监听对象，监听对象将数据u存入buffer

    //组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    ps.header.frame_id="laser";
    ps.header.stamp=ros::Time::now();

    ps.point.x=2.0;
    ps.point.y=3.0;
    ps.point.z=5.0;

    //添加休眠
    ros::Duration(2).sleep();

    //转换算法，调用TF内置实现
    ros::Rate rate(10);

    while (ros::ok)
    {
        //核心代码实现   将ps转换为想对于baselink的坐标点
        geometry_msgs::PointStamped ps_out;
        ps_out = buffer.transform(ps,"base_link");

        //输出
        ROS_INFO("转换后的坐标值：（%.2f,%.2f,%.2f,%.2f）,参考坐标系：%s",ps_out.point.x,   ps_out.point.y,ps_out.point.z,ps_out.header.frame_id.c_str());

        rate.sleep();

        ros::spinOnce();
    }

    /* code */
    return 0;
}

