#include "function.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
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

pros::MotorGroup leftMotors({-14, -15, -16}, pros::MotorGearset::blue); // left motors on ports 14, 15, 16
pros::MotorGroup rightMotors({3, 12, 13}, pros::MotorGearset::blue); // right motors on ports 11, 12, 13

// Inertial Sensor on port 10
pros::Imu imu(7);
// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation horizontalEnc(20);
// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation verticalEnc(19);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, Omniwheel::NEW_275, 0.9);//Tracking Center at middle of drive (for at intake: 6.9)
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, Omniwheel::NEW_275, 2.063);//2.8395, 2.8

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              13, // 13 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              450, // drivetrain rpm is 450
                              8 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linear_controller(31, // proportional gain (kP) (32) (31 for 8.5" no goal)
                                              0, // integral gain (kI) (0)
                                              213 , // derivative gain (kD) (212) (215 for 8.5" no goal)
                                               0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angular_controller(4.52, // proportional gain (kP) (4.59 for 180)(4.53 for 62(no goal))
                                              0.0000, // integral gain (kI) (0.0009 for 180) (0.0029 for 62 (no goal))
                                              47, // derivative gain (kD)(52.88 for 180)(43 for 62 (no goal))
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
pros::Motor IntakeMotor (-18);
pros::Optical Ring_Optical (2);
pros::Distance Ring_Distance (21);
bool Color_Switch = false;

// Wall Stake 
pros::MotorGroup WallStakeMotors ({8, -9}, pros::v5::MotorGears::green);
pros::Rotation WallStakeRotation (1);
float target_position;
// LadyBrown Pid controller
PID LadyBrown_pid (0.45, 0, 0.001);

// Clamp
pros::adi::Pneumatics Clamp_Piston('h', false);   // Starts extended, retracts when the ADI port is high
pros::Optical AutoClamp_Optical (17);
bool ClampDown = false; // by default, the clamp will be up.
bool ClampUp = true;

// Hang
pros::adi::Pneumatics PTO_Piston('c', false);   // Starts retracted, extends when the ADI port is high
pros::adi::Pneumatics Ratchet_Piston('d', false);   // Starts retracted, extends when the ADI port is high
bool hang_locked = true;
bool PTO_Engage = false; // by default, the PTO will be unengaged with the drive (locked)

// Doinker
pros::adi::Pneumatics RightDoinker_Piston('a', false);   // Starts retracted, extends when the ADI port is high
bool RightDoinker_Down = false;
pros::adi::Pneumatics LeftDoinker_Piston('b', false);   // Starts retracted, extends when the ADI port is high
bool LeftDoinker_Down = false;

//Override
bool ClampOver = false;
bool SortOver = false;

//Aditional Vairbles
bool Blue_Alliance = false;
}

