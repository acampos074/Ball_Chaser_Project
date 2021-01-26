
# Ball Chaser Project

This is the second ROS project from the Udacity [Robotics Software Engineer](https://www.udacity.com/course/robotics-software-engineer--nd209) course.

## Overview

The robot's task is to chase a white ball and stop if either the ball is outside of the robot's camera view or if it gets too close to it to avoid a collision.

### License

The source code is released under an [MIT license.](https://opensource.org/licenses/MIT)

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
catkin_make
```

## Usage

Navigate to the ```/src/scripts``` directory, and launch the shell script:

```./chase_ball.sh```

## Launch files
* **world.launch**: Gazebo launch and world file
* **ball_chaser.launch**: The robot's ball chaser algorithm

## Nodes

### **drive_bot**

**Published Topics**
* **```/cmd_vel```** [(geometry_msgs/Twist)](http://docs.ros.org/en/api/geometry_msgs/html/msg/Twist.html)

    Contains the linear and angular velocities to move the robot

**Services**
* **```/ball_chaser/command_robot```**

   Publishes linear and angular velocities to the robot's wheel joints and provides a response message to the **client** containing the requested velocities.

### **process_image**

**Subscribed Topics**
* **```/camera/rgb/image_raw```** [(sensor_msgs/Image)](http://docs.ros.org/en/melodic/api/sensor_msgs/html/msg/Image.html)

   Reads the image data of an RGB camera

**Services**
* **```/ball_chaser/command_robot```**

   Calls the **server** and sends the linear and angular velocities from the *process_image_callback* function.

## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/acampos074/Ball_Chaser_Project/issues)
