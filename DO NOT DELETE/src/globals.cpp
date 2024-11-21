#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/imu.hpp"
#include "pros/rotation.hpp"
#include "globals.hpp"
#include <cmath> // For std::isnan
#include <string> // For std::to_string

using namespace lemlib;

namespace Globals {

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({6, -3, -1}, pros::MotorGearset::blue); // left motor group - ports 3 (reversed), 4, 5 (reversed)
pros::MotorGroup rightMotors({-2, 4, 7},                                                                                                                                                                                                                                                                                                               pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

// Inertial Sensor on port 10
pros::Imu imu(15);
// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation horizontalEnc(-8);
// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation verticalEnc(9);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -1.625);//Tracking Center at middle of drive (for at intake: 6.9)
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, -1.75);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              13, // 13 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            16, // derivative gain (kD)
                                            0, // anti windup
                                            0, // small error range, in inches
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in inches
                                            0, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(3.4, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             22, // derivative gain (kD)
                                             0, // anti windup
                                             0, // small error range, in degrees
                                             0, // small error range timeout, in milliseconds
                                             0, // large error range, in degrees
                                             0, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

// Intake
pros::MotorGroup IntakeMotors ({10, -5});
pros::Optical RingSorter_Optical (15);
bool Color_Switch = false;

// Clamp
pros::adi::Pneumatics Clamp_Piston('h', false);   // Starts retracted, extends when the ADI port is high
pros::Optical AutoClamp_Optical (14);
bool ClampDown = false; // by default, the clamp will be up.

// Hang
pros::adi::Pneumatics PTO_LeftPiston('b', false);   // Starts retracted, extends when the ADI port is high
pros::adi::Pneumatics PTO_RightPiston('c', false);   // Starts retracted, extends when the ADI port is high
pros::Rotation HangConveyor_Rotation(21);
bool hang_locked = false;
bool PTO_Engage = false; // by default, the PTO will be unengaged with the drive (locked)

// Doinker
pros::adi::Pneumatics Doinker_Piston('g', false);   // Starts retracted, extends when the ADI port is high
bool DoinkerDown = false;

}