#!/bin/sh
#xterm -e " source ../../devel/setup.bash; roslaunch my_robot world.launch world_file:=/home/campo074/Udacity/Project2/catkin_ws/src/my_robot/world/andres.world" &
xterm -e " source ../../devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm -e " source ../../devel/setup.bash; roslaunch ball_chaser ball_chaser.launch" &
sleep 5
xterm -e " source ../../devel/setup.bash; rosrun rqt_image_view rqt_image_view"
