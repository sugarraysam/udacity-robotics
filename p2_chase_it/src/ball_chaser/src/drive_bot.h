#include "ball_chaser/DriveToTarget.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "ros/service_server.h"

class DriveBot {
private:
  ros::NodeHandle _n;
  ros::Publisher _pub;
  ros::ServiceServer _srv;
  const std::string _pub_topic{"/cmd_vel"};
  const std::string _srv_topic{"/ball_chaser/command_robot"};

public:
  DriveBot();
  bool handle_drive_request(ball_chaser::DriveToTarget::Request &req,
                            ball_chaser::DriveToTarget::Response &resp);

  static const std::string node_name;
};
