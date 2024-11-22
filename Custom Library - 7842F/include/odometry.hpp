#pragma once
#include "main.h"
#include "globals.h"

//Definition of the Odom class
class Odom
{
public:
  void start();
private:
  int TrackerWheel_diameter;
  float VerticalTracker_center_distance;
  float HorizontalTracker_center_distance;
  float VerticalTracker_position;
  float HorizontalTracker_position;
public:
  float X_position;
  float Y_position;
  float orientation_deg;
  float orientation_offset;
  void set_position(float X_position, float Y_position, float orientation_deg, float VerticalTracker_position, float HorizontalTracker_position);
  //Decleration of the member function that completes the tracking algorithm steps
  void update_position(); 
  void set_physical_distances(float VerticalTracker_center_distance, float HorizontalTracker_center_distance, int TrackerWheel_diameter);
};

//An external decleration of an instance of the Odom clas
//Allows for the odom instance to be accessed accros multiple files
extern Odom odom;

//test text