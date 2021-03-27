#include "ros/ros.h"

#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
    需求：发布两个坐标系间的相对关系
*/


int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");

    //初始化节点
    ros::init(argc,argv,"static_pub");

    //设置句柄
    ros::NodeHandle nh;

    //创建发布
    tf2_ros::StaticTransformBroadcaster pub;

    //组织被发布的消息
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp=ros::Time::now();  
    tfs.header.frame_id="base_link";    //相对坐标系中被参考的
    tfs.child_frame_id="laser";         //雷达坐标系

    tfs.transform.translation.x=0.2;
    tfs.transform.translation.y=0.0;
    tfs.transform.translation.z=0.5;

    //需根据欧拉角色绘制
    tf2::Quaternion qtn;                //创建四元数对象
    qtn.setRPY(0,0,0);                  //像该对象设置欧拉角，可以将其转化为四元数
                                        //单位为弧度
    tfs.transform.rotation.x=qtn.getX();
    tfs.transform.rotation.x=qtn.getY();
    tfs.transform.rotation.x=qtn.getZ();
    tfs.transform.rotation.x=qtn.getW();
  
    //发布数据
    pub.sendTransform(tfs);
    //spin()
    ros::spin();

    /* code */
    return 0;
}

