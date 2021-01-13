#include "drive_bot.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/subscriber.h"
#include <sensor_msgs/Image.h>

// TODO set subscriber, client, server, node name as static class member that
// dont require an instance of the class for easy access e.g.:
// ProcessImage::subscriber_name (const, constexpr? string?)
// TODO refactor ProcessImage ++ DriveBot
class ProcessImage {
private:
  ros::NodeHandle _n;
  ros::ServiceClient _client;
  ros::Subscriber _sub;
  const std::string _client_srv{"/ball_chaser/command_robot"};
  const std::string _sub_topic{"/camera/rgb/image_raw"};

public:
  ProcessImage();
  void drive_robot(float lin_x, float ang_z);
  void process_image_callback(const sensor_msgs::Image img);

  static const std::string node_name;
};
