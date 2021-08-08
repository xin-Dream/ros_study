#include "ros/ros.h"
#include "std_msgs/String.h"
#include "plumbing_pub_sub/Person.h"

int main(int argc, char *argv[])
{
    /* code */

    setlocale(LC_ALL, "");
    ROS_INFO("消息发布方");

    ros::init(argc, argv, "banzhuren");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaotian", 10);

    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age = 1;
    person.height = 1.73;

    ros::Rate rate(1);

    while (ros::ok())
    {
        person.age += 1;

        /* code */
        pub.publish(person);
        ROS_INFO("发布的消息：%s ,%d ,%.2f",person.name.c_str(),person.age,person.height);

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
