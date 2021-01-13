#include "drive_bot.h"

const std::string DriveBot::node_name = "drive_bot";

DriveBot::DriveBot() {
  _pub = _n.advertise<geometry_msgs::Twist>(_pub_topic, 10);
  _srv = _n.advertiseService(_srv_topic, &DriveBot::handle_drive_request, this);
  ROS_INFO("Ready to send twist commands");
}

bool DriveBot::handle_drive_request(
    ball_chaser::DriveToTarget::Request &req,
    ball_chaser::DriveToTarget::Response &resp) {
  ROS_INFO("DriveToTarget Request received - linear_x: %1.2f, angular_z: %1.2f",
           (float)req.linear_x, (float)req.angular_z);

  geometry_msgs::Twist twist;
  twist.linear.x = req.linear_x;
  twist.angular.z = req.angular_z;
  _pub.publish(twist);

  resp.msg_feedback =
      "Linear velocity set to " + std::to_string(req.linear_x) +
      " and Angular velocity (z) set to :" + std::to_string(req.angular_z);
  ROS_INFO_STREAM(resp.msg_feedback);

  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, DriveBot::node_name);
  DriveBot db;
  ros::spin();
  return 0;
}
