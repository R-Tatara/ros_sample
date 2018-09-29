#include "ros/ros.h"
#include "rostopic_sample/MsgSample.h"

void msgCallback(const rostopic_sample::MsgSample::ConstPtr& msg) {
  //ROS_INFO("recieve msg = %d", msg->data1);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "topic_subscriber1");
  ros::NodeHandle nh;
  ros::Publisher ros_pub = nh.advertise<rostopic_sample::MsgSample>("ros_msg2", 100);
  ros::Subscriber ros_sub = nh.subscribe("ros_msg1", 100, msgCallback);
  ros::Rate loop_rate(1000);
  rostopic_sample::MsgSample msg;

  int count2 = 0;

  while (ros::ok()) {
    msg.data2  = count2;
    ros_pub.publish(msg);
    //ROS_INFO("send msg = %d", msg.data2);
    ros::spinOnce();
    loop_rate.sleep();
    count2++;
  }

  return 0;
}
