#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "globals.hpp"
#include "function.hpp"
#include "auton_selector.hpp"
#include "autons.hpp"
using namespace Globals;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
    chassis.calibrate(); // calibrate sensors
    AutoClamp_Optical.set_led_pwm(100);
    RingSorter_Optical.set_integration_time(712);
    // AutoClamp_Optical.set_integration_time(712);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy
ASSET(SoloWin1_txt); // '.' replaced with "_" to make c++ happy
ASSET(SAWPNegative_txt); // '.' replaced with "_" to make c++ happy
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
//  chassis.setPose(0, 0, 0);
// //  chassis.moveToPoint(0, 24, 4000);
// chassis.turnToHeading(90, 2000);

   
// SAWP_NegativeFull_Red_BarcBot();

    pros::Task Clamp(Auto_Clamp);
    pros::Task Sort(Intake);

	/*Drive Controls*/
   
         while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);
      
/*Intake Controls*/

        
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