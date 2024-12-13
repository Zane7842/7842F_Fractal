#pragma once
#include "function.hpp"
#include "main.h"
#include "globals.hpp"
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
extern lemlib::ControllerSettings linearController;

// angular motion controller
extern lemlib::ControllerSettings angularController;

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
extern int Ring_Hue;

// Clamp
extern pros::adi::Pneumatics Clamp_Piston;
extern pros::Optical AutoClamp_Optical;
extern bool ClampDown;

//WallStake 
extern pros::MotorGroup WallStakeMotors;
extern float target_position;
extern lemlib::PID LadyBrown_pid;

// Hang
extern pros::adi::Pneumatics PTO_LeftPiston;
extern pros::adi::Pneumatics PTO_RightPiston;
extern bool PTO_Engage;

// Doinker
extern pros::adi::Pneumatics Doinker_Piston;
extern bool DoinkerDown;

// overides
extern bool ClampOver;
extern bool SortOver;
}