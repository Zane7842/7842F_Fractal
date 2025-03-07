#include "function.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "globals.hpp"
#include <cmath> // For std::isnan
#include <string> // For std::to_string

using namespace lemlib;

namespace Globals {

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller_mechops(pros::E_CONTROLLER_MASTER);
// motor groups                                                                                                                                                                                                                                                                                            pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

pros::MotorGroup leftMotors({-8, -7, -6}, pros::MotorGearset::blue); // left motors on ports 14, 15, 16
pros::MotorGroup rightMotors({3, 4, 5}, pros::MotorGearset::blue); // right motors on ports 11, 12, 13

// Inertial Sensor on port 10
pros::Imu imu(18);
// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation horizontalEnc(-20);
// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation verticalEnc(-19);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, Omniwheel::NEW_275, -0.1 );//1.75 (-0.28)
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, Omniwheel::NEW_275, -0.5);//-0.4375 (-0.135)

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              11.3125, // 13 inch track width
                              2, // using new 2" omnis
                              800, // drivetrain rpm is 800
                              8 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linear_controller(60, // proportional gain (kP) (33) (34) (35) (39) (40) (47) (48) (49) (50) (55) (60)
                                              0, // integral gain (kI) (0)
                                              393 , // derivative gain (kD) (170 (230) (230) (235) (240) (285) (305) (305) (306) (345) (390)
                                               0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angular_controller(4.4, // proportional gain (kP) (4.59 for 180)(4.53 for 62(no goal))
                                              0.000, // integral gain (kI) (0.0009 for 180) (0.0029 for 62 (no goal))
                                              46, // derivative gain (kD)(52.88 for 180)(43 for 62 (no goal))
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)v
);

// sensors for odometryp
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(2.4, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(2.1, // joystick deadband out of 127
                                  13, // minimum output where drivetrain will move out of 127
                                  1.014 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linear_controller, angular_controller, sensors, &throttleCurve, &steerCurve);

// Intake
pros::Motor IntakeMotor (21);
pros::Optical Ring_Optical (17);
pros::Distance Ring_Distance (13);
bool Color_Switch = false;
int desired_ring = 0;
bool undesired_ring = 1;

// Wall Stake 
pros::MotorGroup WallStakeMotors ({-2, 9}, pros::v5::MotorGears::green);
pros::Rotation WallStakeRotation (1);
float target_position;
// LadyBrown Pid controller
PID LadyBrown_pid (0.45, 0, 0.001); //test comment
double start_offset = 0;

// Clamp
pros::adi::Pneumatics Clamp_Piston('h', true);   // Starts extended, retracts when the ADI port is high
pros::Distance AutoClamp_Distance (11);
bool ClampDown = false; //conditiuon check variable for autons
bool ClampUp = true; // by default, the clamp will be up.

// Doinker
pros::adi::Pneumatics RightDoinker_Piston('c', false);   // Starts retracted, extends when the ADI port is high
bool RightDoinker_Down = false;
pros::adi::Pneumatics LeftDoinker_Piston('b', false);   // Starts retracted, extends when the ADI port is high
bool LeftDoinker_Down = false;

//Aditional Vairbles
bool Blue_Alliance = false;
}

