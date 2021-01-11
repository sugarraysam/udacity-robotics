TARGETS := build run clean help
.PHONY: $(TARGETS)

build:
	@cmake -B _build
	@cd _build && make
	@ln -sf _build/compile_commands.json compile_commands.json

run: build
	@GAZEBO_PLUGIN_PATH="$(GAZEBO_PLUGIN_PATH):$(PWD)/_build" gazebo world/hello.world --verbose

clean:
	-@rm -fr _build

help:
	@echo "make [ $(TARGETS) ]"
