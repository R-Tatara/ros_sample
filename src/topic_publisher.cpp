#include "ros/ros.h"
#include "rostopic_sample/MsgSample.h"

void msgCallback(const rostopic_sample::MsgSample::ConstPtr& msg) {
  //ROS_INFO("recieve msg = %d", msg->data2);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "topic_publisher");
  ros::NodeHandle nh;
  ros::Publisher ros_pub = nh.advertise<rostopic_sample::MsgSample>("ros_msg1", 100);
  ros::Subscriber ros_sub = nh.subscribe("ros_msg2", 100, msgCallback);
  ros::Rate loop_rate(1000);
  rostopic_sample::MsgSample msg;

  int count1 = 0;

  while (ros::ok()) {
    msg.data1  = count1;
    ros_pub.publish(msg);
    ROS_INFO("send msg = %d", msg.data1);
    ros::spinOnce();
    loop_rate.sleep();
    count1++;
  }

  return 0;
}
