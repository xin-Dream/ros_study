#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "static_pub");
    ros::NodeHandle nh;

    tf2_ros::StaticTransformBroadcaster pub;

    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";
    tfs.child_frame_id = "laser";

    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.4;  

    //四元数设置，根据欧拉角设置
    //创建四元数对象
    tf2::Quaternion qtn;
    //向对象设置欧拉角，并转换为四元数
    qtn.setRPY(0.0, 0.0, 0.0);//单位为弧度

    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    pub.sendTransform(tfs);

    ros::spin();

    return 0;
}
