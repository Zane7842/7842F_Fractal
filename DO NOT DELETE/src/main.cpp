#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "globals.hpp"
#include "function.hpp"

using namespace Globals;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });

}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy
ASSET(TestPath_txt); // '.' replaced with "_" to make c++ happy
ASSET(SimpleTest_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    // Move to x: 20 and y: 15, and face heading 90. Timeout set to 4000 ms
    chassis.moveToPose(20, 15, 90, 4000);
    // Move to x: 0 and y: 0 and face heading 270, going backwards. Timeout set to 4000ms
    chassis.moveToPose(0, 0, 270, 4000, {.forwards = false});
    // cancel the movement after it has traveled 10 inches
    chassis.waitUntil(10);
    chassis.cancelMotion();
    // Turn to face the point x:45, y:-45. Timeout set to 1000
    // dont turn faster than 60 (out of a maximum of 127)
    chassis.turnToPoint(45, -45, 1000, {.maxSpeed = 60});
    // Turn to face a direction of 90º. Timeout set to 1000
    // will always be faster than 100 (out of a maximum of 127)
    // also force it to turn clockwise, the long way around
    chassis.turnToHeading(90, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    // Follow the path in path.txt. Lookahead at 15, Timeout set to 4000
    // following the path with the back of the robot (forwards = false)
    // see line 116 to see how to define a path
    chassis.follow(TestPath_txt, 15, 4000, false);
    // wait until the chassis has traveled 10 inches. Otherwise the code directly after
    // the movement will run immediately
    // Unless its another movement, in which case it will wait
    chassis.waitUntil(10);
    pros::lcd::print(4, "Traveled 10 inches during pure pursuit!");
    // wait until the movement is done
    chassis.waitUntilDone();
    pros::lcd::print(4, "pure pursuit finished!");
}

/**
 * Runs in driver control
 */
void opcontrol() {


if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X) & controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {

    chassis.setPose(-48, 0, 90);
        // chassis.moveToPose(24, 24, 0, 100000);


chassis.follow(SimpleTest_txt, 10, 100000, true);
    // wait until the chassis has traveled 10 inches. Otherwise the code directly after
    // the movement will run immediately
    // Unless its another movement, in which case it will wait

    }

/*Drive Controls*/

    // controller
   
         while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);
      
/*Intake Controls*/

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        IntakeMotors.move_voltage(12000);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        IntakeMotors.move_voltage(-12000);
        }
        else {
        IntakeMotors.move_voltage(0);
        }
        //Ring Sort
        Ring_Sort ();
        
 /*Clamp Controls*/

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
            // If this is true, ClampDown will changed to false
            // and vice versa. 
            ClampDown = !ClampDown; 
        }
        
        // If ClampDown is true, move the pistons.         
        if(ClampDown) {
            Clamp_Piston.set_value(true);
        }
        // Else, don't
        else {
            Clamp_Piston.set_value(false);
        }

        //Auto Clamp
        Auto_Clamp ();

/*Hang Controls*/

        // if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) { 
        //     Set_Hang ();
        // }
        // else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
        //     Start_Hang ();
        // }

        // if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){

        // }

/*Doinker Controls*/

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
                    // If this is true, ClampDown will changed to false
                    // and vice versa. 
                    DoinkerDown = !DoinkerDown; 
                }
                
                // If ClampDown is true, move the pistons.         
                if(DoinkerDown) {
                    Doinker_Piston.set_value(true);
                }
                // Else, don't
                else {
                    Doinker_Piston.set_value(false);
                }

        // delay to save resources
        pros::delay(25);  
    }
}

