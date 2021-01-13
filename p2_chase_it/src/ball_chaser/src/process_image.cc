#include "process_image.h"
#include "ball_chaser/DriveToTarget.h"
#include "ros/node_handle.h"

const std::string ProcessImage::node_name = "process_image";

ProcessImage::ProcessImage() {
  _client = _n.serviceClient<ball_chaser::DriveToTarget>(_client_srv);
  _sub =
      _n.subscribe(_sub_topic, 10, &ProcessImage::process_image_callback, this);
}

void ProcessImage::drive_robot(float lin_x, float ang_z) {
  ROS_INFO_STREAM("Driving robot towards the white ball");

  ball_chaser::DriveToTarget srv;
  srv.request.linear_x = lin_x;
  srv.request.angular_z = ang_z;

  if (!_client.call(srv))
    ROS_ERROR_STREAM("Failed to call service " + _client_srv);
}

void ProcessImage::process_image_callback(const sensor_msgs::Image img) {
  int white_pixel = 255;
  float left_boundary = img.step / 3.0f;
  float right_boundary = (2.0f / 3.0f) * img.step;
  float lin_x{0.0};
  float ang_z{0.0};

  for (int i = 0; i < img.step * img.height; ++i) {
    if (img.data[i] == white_pixel) {
      float pos = i % img.step;
      if (pos < left_boundary) {
        // left
        lin_x = 0.0;
        ang_z = 0.5;
      } else if (pos >= right_boundary) {
        // right
        lin_x = 0.0;
        ang_z = -0.5;
      } else {
        // forward
        lin_x = 0.5;
        ang_z = 0.0;
      }
      break;
    }
  }
  // will stop if white ball is not seen (default lin_x & ang_z)
  this->drive_robot(lin_x, ang_z);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, ProcessImage::node_name);
  ProcessImage pi;
  ros::spin();
  return 0;
}
