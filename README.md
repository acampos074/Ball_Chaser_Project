
# Ball Chaser Project

This is the second ROS project from the Udacity [Robotics Software Engineer](https://www.udacity.com/course/robotics-software-engineer--nd209) course.

## Overview

The robot's task is to chase a white ball and stop if either the ball is outside of the robot's camera view or if it gets too close to it to avoid a collision.

### License

**Author: Andres Campos**

Both ```my_robot``` and ```ball_chaser``` packages have been tested under  [ROS](https://www.ros.org/) Kinetic on Ubuntu 16.04. This code is for personal learning and any fitness for a paticular purpose is disclaimed. 

## Installation

### Installation from Packages
To install all packages from this repository as Debian packages use

```sudo apt-get install ros-kinetic-...```

Or use ```rosdep```:

```sudo rosdep install --from-paths src```

### Building from Source

#### Dependencies
* [Robotics Operating System (ROS)](https://www.ros.org/) (middleware for robotics)

```sudo rosdep install --from-paths src```

#### Building
To build from source, clone the latest version from this repository into your catkin workspace and compile this package using
```
cd catkin_workspace/src
git clone https://github.com/acampos074/Ball_Chaser_Project.git
cd ../
rosdep install --from-paths . --ignore-src
catkin_make
```
### Running in Docker

Docker helps to run an application with all dependencies and libraries bundled together. Make sure to [install Docker](https://docs.docker.com/get-docker/)first.

First run:

```docker run -ti --rm --name ros-container ros:kinetic bash```

Next, create a catkin workspace, clone the package, and build it:

```
apt-get update && apt-get install -y git
mkdir -p /ws/src && cd /ws/src
git clone https://github.com/acampos074/Ball_Chaser_Project.git
cd ..
rosdep install --from-path src
catkin_make
source devel/setup.bash
roslaunch ros_package_template ros_package_template.launch
```

## Usage

Run this code to launch the ```my_robot``` ROS package which contains the robot and the world:

```roslaunch my_robot world.launch```

The ```ball_chaser.launch``` will run both nodes ```drive_bot``` and ```process image```. On a different terminal, run the ```ball_chaser``` ROS package:

```roslaunch ball_chaser ball_chaser.launch```

To visualize the robot's camera view, you can run the ```rqt_image_view``` node:

```rosrun rqt_image_view rqt_image_view```

## Launch files
* **world.launch**:
* **ball_chaser.launch**:

## Nodes

### **drive_bot**

**Subscribed Topics**

**Published Topics**
* **```/cmd_vel```**[geometry_msgs/Twist](http://docs.ros.org/en/api/geometry_msgs/html/msg/Twist.html)
    
    The linear and angular velocities to move the robot
    
**Services**
* **```command_robot```**

   Publishes linear and angular velocities to the robot's wheel joints and returns the requested velocities. 

**Parameters**

### **process_image**

**Subscribed Topics**

**Published Topics**

**Services**
* **```???```**

   Requests a service via a client to drive the robot towards the white ball

**Parameters**

## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/acampos074/Ball_Chaser_Project/issues)

