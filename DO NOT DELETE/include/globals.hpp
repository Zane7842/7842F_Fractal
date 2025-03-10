#pragma once
#include "function.hpp"
#include "main.h"
#include "globals.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "lemlib/chassis/chassis.hpp"

namespace Globals {

// controller
extern pros::Controller controller;
extern pros::Controller controller_mechops;

// motor groups
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

// Inertial Sensor on port 10
extern pros::Imu imu;

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
extern pros::Rotation horizontalEnc;
// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
extern pros::Rotation verticalEnc;
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
extern lemlib::TrackingWheel horizontal;
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
extern lemlib::TrackingWheel vertical;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

// lateral motion controller
extern lemlib::ControllerSettings linear_controller;

// angular motion controller
extern lemlib::ControllerSettings angular_controller;

// sensors for odometry
extern lemlib::OdomSensors sensors;

// input curve for throttle input during driver control
extern lemlib::ExpoDriveCurve throttleCurve;

// input curve for steer input during driver control
extern lemlib::ExpoDriveCurve steerCurve;

// create the chassis
extern lemlib::Chassis chassis;

//-----------------------------------------------------------

// Intake
extern pros::Motor IntakeMotor;
extern pros::Optical Ring_Optical;
extern pros::Distance Ring_Distance;
extern int Ring_Hue;
extern int desired_ring;
extern bool undesired_ring;

// Clamp
extern pros::adi::Pneumatics Clamp_Piston;
extern pros::Distance AutoClamp_Distance;
extern bool ClampDown;
extern bool ClampUp;

//WallStake 
extern pros::MotorGroup WallStakeMotors;
extern pros::Rotation WallStakeRotation;
extern float target_position;
extern lemlib::PID LadyBrown_pid;
extern double start_offset;

// Doinker
extern pros::adi::Pneumatics RightDoinker_Piston;
extern bool RightDoinker_Down;
extern pros::adi::Pneumatics LeftDoinker_Piston;
extern bool LeftDoinker_Down;

//Addition varibles
extern bool Blue_Alliance;
}