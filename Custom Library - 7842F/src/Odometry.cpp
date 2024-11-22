#include "liblvgl/llemu.hpp"
#include "main.h"
#include "odometry.hpp"
#include "globals.h"
#include <string>

using namespace Globals; //Allows access rotation sensors and IMU_sensor


//namespace Odometry {

/* Function to convert degrees to radiens */
float to_rad (float degree) {return degree*(M_PI / 180.0);}


void Odom::start(){
    //Lambda function to continiously call update_position in a separate task
    pros::Task task ([&](){
        while (true) {
            this->update_position();
            pros::delay(10); 
        }
    });
}

void Odom::set_physical_distances(float VerticalTracker_center_distance, float HorizontalTracker_center_distance, int TrackerWheel_diameter){
  this->TrackerWheel_diameter = TrackerWheel_diameter;
  this->VerticalTracker_center_distance = VerticalTracker_center_distance;
  this->HorizontalTracker_center_distance = HorizontalTracker_center_distance;
}


// Type Class_Name::Member_Function_Name(){Insert code}


void Odom::set_position(float X_position = 0, float Y_position = 0, float orientation_deg = 0, float VerticalTracker_position = 0, float HorizontalTracker_position = 0){
  this->VerticalTracker_position = VerticalTracker_position;
  this->HorizontalTracker_position = HorizontalTracker_position;
  this->X_position = X_position;
  this->Y_position = Y_position;
  this->orientation_deg = orientation_deg;
  this->orientation_offset = orientation_deg;
}

/*
 *Odometry Function: Does the odometry math to update position
 * Uses the Pilons arc method outline here: https://wiki.purduesigbots.com/software/

 *Parameters = (X position, Y Position, Orientation) -> of the Robot's starting position for an autonomous routine
 *Cordinates and heading are feild centred
   - Cartesian Cordinate:(0,0) = located in the center of the field
   - Orientation (heading) = clockwise-positive
   - Y axis is along double line on High Stakes Field
   - Posistive y direction is towards negative corners

 *Uses 2 Tracking Wheels
 *Tracking Wheels are equiped with their respective rotation sensors:
   - (VerticalTracker) uses the (Vertical_rotation) sensor
   - (HorizontalTracker) uses the (Horizontal_rotation) sensor
 */

void Odom::update_position(){

  /*Step 1: Store the current encoder and inertial values in local variables*/

  // Stores new encoder values via the rotation sensor's .get_position function
  float VerticalTracker_position = Vertical_rotation.get_position(); 
  float HorizontalTracker_position = Horizontal_rotation.get_position(); 
  // Stores new orientation via the imu_sensor's .get_heading function
  float orientation_deg = imu_sensor.get_heading()+orientation_offset;

  /*Step 2:*/
  // this-> always refers to the old version of the variable, so subtracting this->x from x gives delta x.
  float Vertical_delta = VerticalTracker_position-this->VerticalTracker_position;
  float Horizontal_delta = HorizontalTracker_position-this->HorizontalTracker_position;
  // Converts position (in degrees) to distance (in inches).
  float Vertical_delta_distance = (M_PI*TrackerWheel_diameter)*(Vertical_delta / 360); 
  float Horizontal_delta_distance = (M_PI*TrackerWheel_diameter)*(Horizontal_delta / 360); 

  /*Step 3: Find change in orientation in radiens*/
  //Using the to_rad function, converts current and old degree variables to radians, stores the radian values in new variables
  float orientation_rad = to_rad(orientation_deg);
  float prev_orientation_rad = to_rad(this->orientation_deg);
  float orientation_delta_rad = orientation_rad-prev_orientation_rad;

  /*Step 4: Updates the previous sensor values*/
  //Updates Vertical Tracker position
  this->VerticalTracker_position=VerticalTracker_position; 
  //Updates Horizontal Tracker position
  this->HorizontalTracker_position=HorizontalTracker_position;
  //Updates orientation in degrees
  this->orientation_deg=orientation_deg;

  /*Step 5: Calculates local offsets*/
  float local_X_position;
  float local_Y_position;

  //If the orientation is at 0...
  if (orientation_delta_rad == 0) {
    local_X_position = Horizontal_delta; //Local X is 
    local_Y_position = Vertical_delta;
  } else {
    local_X_position = (2*sin(orientation_delta_rad/2))*((Horizontal_delta/orientation_delta_rad)+HorizontalTracker_center_distance); 
    local_Y_position = (2*sin(orientation_delta_rad/2))*((Vertical_delta/orientation_delta_rad)+VerticalTracker_center_distance);
  }

  float local_polar_angle;
  float local_polar_length;

  if (local_X_position == 0 && local_Y_position == 0){
    local_polar_angle = 0;
    local_polar_length = 0;
  } else {
    local_polar_angle = atan2(local_Y_position, local_X_position); 
    local_polar_length = sqrt(pow(local_X_position, 2) + pow(local_Y_position, 2)); 
  }

  float global_polar_angle = local_polar_angle - prev_orientation_rad - (orientation_delta_rad/2);

  float X_position_delta = local_polar_length*cos(global_polar_angle); 
  float Y_position_delta = local_polar_length*sin(global_polar_angle);

  X_position+=X_position_delta;
  Y_position+=Y_position_delta;



   //Prints Values to the brain screen
  pros::lcd::set_text(0, "X Val: " + std::to_string(X_position));
  pros::lcd::set_text(1, "Y Val: " + std::to_string(Y_position));
  pros::lcd::set_text(2, "imu heading val: " + std::to_string(imu_sensor.get_heading()));
    }

Odom odom;

