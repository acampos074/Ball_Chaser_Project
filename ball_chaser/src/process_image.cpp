#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    //ROS_INFO_STREAM("Driving the robot towards the ball");

    // Request linear and angular velocities
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the safe_move service and pass the requested joint angles
    if (!client.call(srv))
        ROS_ERROR("Failed to call service safe_move");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    int white_pixel_position = 0;
    bool found_white_pixel = false;
    int white_pixel_column = 0;
    int number_of_white_pixels = 0;
    int total_number_of_pixels = img.height*img.width;
    //ROS_INFO("img.height:%1.2f, img.step:%1.2f, img.width:%1.2f", (float)img.height, (float)img.step, (float)img.width);
    // height = 800; step = 2400; width = 800;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    for(int i=0; i < img.height * img.step;  i++)
    {
      if((img.data[i] == white_pixel) && (img.data[i+1] == white_pixel) && (img.data[i+2] == white_pixel))
      {
        // store current index i
        white_pixel_position = i;
        found_white_pixel = true;
        break;
      }
    }

    // Scan the image to calculate the ratio of white pixels to the total number of pixels
    for(int i=0; i < img.height * img.step;  i++)
    {
      if((img.data[i] == white_pixel) && (img.data[i+1] == white_pixel) && (img.data[i+2] == white_pixel))
      {
        // count the number of white pixels found
        number_of_white_pixels++;
      }
    }

    // Determine the white pixel's corresponding column
    white_pixel_column = white_pixel_position%img.width;

    if(found_white_pixel)
    {
      // if the robot is far from the ball it's ok to move, else stop the robot to avoid collision
      if(number_of_white_pixels < (float)total_number_of_pixels*0.7){
        if(white_pixel_column < img.width/3 && white_pixel_column >= 0){
          // if pixel falls in the left
          drive_robot(0.0, 0.5);
          //ROS_INFO("Driving the robot left");
        }
        else if(white_pixel_column >= img.width/3 && white_pixel_column <= img.width*2/3){
          // if pixel falls in the middle
          drive_robot(0.1, 0.0);
          //ROS_INFO("Driving the robot middle");
        }
        else{
          // if pixel falls in the right
          drive_robot(0.0, -0.5);
          //ROS_INFO("Driving the robot right");
        }
      }
      else{
        // Request a stop if the camera cant see the white ball
        drive_robot(0.0, 0.0);
      }

    }
    else{
      // Request a stop if the camera cant see the white ball
      drive_robot(0.0, 0.0);
    }
    // Restart variables
    found_white_pixel = false;
    number_of_white_pixels = 0;
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
