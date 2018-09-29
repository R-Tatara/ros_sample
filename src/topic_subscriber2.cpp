#include "ros/ros.h"
#include "rostopic_sample/MsgSample.h"

void msgCallback(const rostopic_sample::MsgSample::ConstPtr& msg)
{
  //ROS_INFO("recieve msg = %d", msg->data1);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_subscriber2");
  ros::NodeHandle nh;
  ros::Subscriber ros_sub = nh.subscribe("ros_msg1", 100, msgCallback);
  ros::spin();

  return 0;
}
