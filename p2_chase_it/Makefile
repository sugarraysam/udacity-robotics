TARGETS := build launch-world launch-ball-chaser help
.PHONY: $(TARGETS)

export SHELL := /bin/bash

init:
	@catkin_make

build: init
	@source ./devel/setup.bash && catkin_make
	@ln -sf build/compile_commands.json compile_commands.json

launch-world: build
	@source ./devel/setup.bash && roslaunch my_robot world.launch

launch-ball-chaser:
	@source ./devel/setup.bash && roslaunch ball_chaser ball_chaser.launch

help:
	@echo "make [ $(TARGETS) ]"
