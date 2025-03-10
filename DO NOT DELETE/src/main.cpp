#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/misc.h"
#include "globals.hpp"
#include "function.hpp"
#include "auton_selector.hpp"
#include "autons.hpp"
#include "pros/motors.h"
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

    /*Intake*/
    Ring_Optical.set_integration_time(3);
    Ring_Optical.set_led_pwm(100);
    IntakeMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);

    /*Wallstake*/
    WallStakeMotors.set_brake_mode_all(pros::MotorBrake::brake);
    WallStakeMotors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
     pros::Task ladyBrown(LadyBrown);
    // start_offset = 32.9;
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
// ASSET(example_txt); // '.' replaced with "_" to make c++ happy
// ASSET(SoloWin1_txt); // '.' replaced with "_" to make c++ happy
// ASSET(SAWPNegative_txt); // '.' replaced with "_" to make c++ happy
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
void autonomous() {
pros::Task Print(print_odom);

// Tune_LateralPID();

Positive_red_negative_blue();
// ColorSort_test();

//   desired_ring = 3;
// Auton_StopIntake();
}

/**
 * Runs the nmnmmd operator control code. This function will be started in its own task
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

    // while(true){
    // if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
    // Tune_LateralPID();
    // }
    // }

/*Tasks*/
    pros::Task matchClamp(Clamp);
    // pros::Task matchLadyBrown(LadyBrown);
    // pros::Task Sort(Intake);
   
    ClampUp = false; //CHANGED LINE
    bool sort = false;
    bool disable_sort = false;

    
//Main Loop
    while (true) {

/*Intake controlls*/
        if(disable_sort == false){ //extra condition for colro sort disable
            if(get_opticalColor() == undesired_ring){
                sort = true;
            }
            // if(get_opticalColor() == 2 || 1){
            //     sort = false;
            // }
            if(sort == true){
                        //Sort Blue
                if ((Ring_Distance.get() < 40)){ //works with 30
                    // Match_Sort();  
                    IntakeMotor.move_voltage(-12000);
                    pros::delay(500); //Delay to control length of break period (500 works)
                    sort = false;
                }
            }
        }
        //If button R1 is being pressed, spin teh intake forwards at full speed
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //was else if, might not work if its just if
        IntakeMotor.move_voltage(12000);
        }
        else if (!(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
        IntakeMotor.move_voltage(0);
        }
        //If button "Y" is pressed: Sets intake to sort opposite color of the previous sort color
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            undesired_ring = !undesired_ring;   
        }

        //Disable color sort control
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            disable_sort = !disable_sort;   
        }

    // printf("my int: %d\n", get_opticalColor());

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        IntakeMotor.move_voltage(-12000);
        }
        


        
/*Drive Controls*/

        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);
    
/*Clamp Controls*/

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
            // If this is true, ClampUp will changed to false
            // and vice versa. 
            ClampDown = !ClampDown; 
        }
    
        Clamp_Piston.set_value(ClampDown); //sets piston state to the toggle variable (ClampUp)
     
/*Doinker Controls*/

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            // If this is true, DoinkerDown will changed to false
            // and vice versa. 
            RightDoinker_Down = !RightDoinker_Down; 
        }
        RightDoinker_Piston.set_value(RightDoinker_Down);

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            // If this is true, DoinkerDown will changed to false
            // and vice versa. 
            LeftDoinker_Down = !LeftDoinker_Down; 
        }
        LeftDoinker_Piston.set_value(LeftDoinker_Down);

        pros::delay(11);
    }
}