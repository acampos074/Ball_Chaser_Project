#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities

// This callback function executes whenever a safe_move service is requested
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{

    //ROS_INFO("DriveToTarget received - x:%1.2f, z:%1.2f", (float)req.linear_x, (float)req.angular_z);

    // Store variables in a 2-element vector
    std::vector<float> vel = {req.linear_x, req.angular_z};


    // TODO: Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values

        // Create a motor_command object of type geometry_msgs::Twist
        geometry_msgs::Twist motor_command;
        // Set wheel velocities, forward [0.5, 0.0]
        motor_command.linear.x = vel[0];
        motor_command.angular.z = vel[1];
        // Publish angles to drive the robot
        motor_command_publisher.publish(motor_command);
        // Return a response message (might need to get this out of the for loop)
        res.msg_feedback = "Velocities set - x: " + std::to_string(vel[0]) + " , z: " + std::to_string(vel[1]);
        //ROS_INFO_STREAM(res.msg_feedback);
      
    return true;
}


int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Ready to send velocity commands");

    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}
