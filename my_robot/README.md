# my_robot Package

## Overview

**License**

Author: Andres Campos

The my_robot package has been tested under ROS Kinetic on Ubuntu 16.04.

## Installation
**Installation from Packages**

`sudo apt-get install ros-kinetic-...`

**Building from Source**
**Dependencies**
* Robot Operating System (ROS) (middleware for robotics)

**Building**
To build from source, clone the latest version from this repository into your catkin workspace and compile the package using

```
cd catkin_workspace/src
git clone https://github.com/acampos074/Ball_Chaser_Project.git
cd ../
rosdep install --from-paths . --ignore-src
catkin_make
```
**Unit Tests**

## Usage
Run the main node with

`roslaunch my_robot world.launch`

## Config files

## Launch files

## Nodes
**my_robot**
**Subscribed Topics**
**Published Topics**
**Services**
**Parameters**

## Bugs & Feature Requests
Please report bugs and request features using the [Issue Tracker](http://github.com)


