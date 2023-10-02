#!/bin/bash

export ROS_IP=192.168.137.123
export ROS_MASTER_URI=http://192.168.137.57:11311

source /opt/ros/noetic/setup.bash
source /home/ubuntu/catkin_ws/devel/setup.bash
exec "$@"
