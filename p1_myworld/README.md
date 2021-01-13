# Build My World <!-- omit in toc -->

- [Tasks](#tasks)
- [Running the simulation](#running-the-simulation)
- [Resources](#resources)

# Tasks

1. Build a single floor wall structure using the Building Editor tool in Gazebo. Apply at least one feature, one color, and optionally one texture to your structure. Make sure there's enough space between the walls for a robot to navigate.
2. Model any object of your choice using the Model Editor tool in Gazebo. Your model links should be connected with joints.
3. Import your structure and two instances of your model inside an empty Gazebo World.
4. Import at least one model from the Gazebo online library and implement it in your existing Gazebo world.
5. Write a C++ World Plugin to interact with your world. Your code should display `Welcome to My World!` message as soon as you launch the Gazebo world file.

# Running the simulation

Make sure you have gazebo installed on your development machine and simply run:

```bash
# Build the gazebo plugin locally, and dynamically linked it into the simulation.
$ make run

<CTRL-C> # exit

# Clean local directory
$ make clean
```

# Resources

- [Gazebo Tutorial - Hello World Plugin!](http://gazebosim.org/tutorials/?tut=plugins_hello_world)
- [Gazebo Tutorial - Model Editor](http://gazebosim.org/tutorials?tut=guided_b3)
