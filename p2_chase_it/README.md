# Go Chase It! <!-- omit in toc -->

**Description**

In this project, we create a `ball_chaser` ROS package. It contains two nodes that will help detect and chase a white ball. The detection is done through camera sensor image parsing, and the chasing is done by sending twist messages to drive the robot.

- [Tasks](#tasks)
- [Running the simulation](#running-the-simulation)

# Tasks

**`drive_bot`:**

- Create a my_robot ROS package to hold your robot, the white ball, and the world.
- Design a differential drive robot with the Unified Robot Description Format.
- Add two sensors to your robot: a lidar and a camera.
- Add Gazebo plugins for your robot’s differential drive, lidar, and camera.
- House your robot inside the world you built in the Build My World project.
- Add a white-colored ball to your Gazebo world and save a new copy of this world.
- The world.launch file should launch your world with the white-colored ball and your robot.

**`ball_chaser`:**

- Create a ball_chaser ROS package to hold your C++ nodes.
- Write a `drive_bot` C++ node that will provide a `/ball_chaser/command_robot` service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
- Write a `process_image` C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
- The `ball_chaser.launch` should run both the drive_bot and the process_image nodes.

# Running the simulation

Make sure you have gazebo and ros noetic installed on your development machine and run:

```bash
# Build the gazebo plugins
$ make build

# Terminal #1 - Run the world
$ make launch-world

# Terminal #2 - Run the `drive_bot` and `process_image` nodes
$ make launch-ball-chaser

<CTRL-C> # exit from both terminal

# Clean local directory
$ make clean
```
