#include "function.hpp"
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
pros::Controller controller_mechops(pros::E_CONTROLLER_MASTER);
// motor groups                                                                                                                                                                                                                                                                                                               pros::MotorGearset::blue); // right motor group - ports 6, 7, 9 (reversed)

pros::MotorGroup leftMotors({-11, -12, -13}); // left motors on ports 1, 2, 3
pros::MotorGroup rightMotors({1, 2, 3}); // right motors on ports 4, 5, 6

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
lemlib::ControllerSettings linearController(15, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            110, // derivative gain (kD)
                                            0, // anti windup
                                            0, // small error range, in inches
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in inches
                                            0, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(4, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             30, // derivative gain (kD)
                                             0, // anti windu
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
pros::Motor IntakeMotors (15);
pros::Optical Ring_Optical (8);
bool Color_Switch = false;

//Wall Stake 
pros::MotorGroup WallStakeMotors ({-20, 19});
bool WallStake = false;

// LadyBrown Pid controller
PID LadyBrown_pid (5, 0, 20);

// Clamp
pros::adi::Pneumatics Clamp_Piston('h', true);   // Starts extended, retracts when the ADI port is high
pros::Optical AutoClamp_Optical (20);
bool ClampDown = false; // by default, the clamp will be up.

// Hang
pros::adi::Pneumatics PTO_LeftPiston('c', false);   // Starts retracted, extends when the ADI port is high
pros::adi::Pneumatics PTO_RightPiston('d', false);   // Starts retracted, extends when the ADI port is high
pros::Rotation HangConveyor_Rotation(21);
bool hang_locked = false;
bool PTO_Engage = false; // by default, the PTO will be unengaged with the drive (locked)

// Doinker
pros::adi::Pneumatics Doinker_Piston('a', false);   // Starts retracted, extends when the ADI port is high
bool DoinkerDown = false;

//Override
bool ClampOver = false;
bool SortOver = false;
}