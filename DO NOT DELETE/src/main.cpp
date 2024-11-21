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
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    drawGUI();


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
ASSET(SoloWin1_txt); // '.' replaced with "_" to make c++ happy
ASSET(SAWPNegative_txt); // '.' replaced with "_" to make c++ happy
/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {

    
    int selectedAuton = autonSelector.getSelectedAuton();

    if (selectedAuton == 0) {
        std::cout << "Running Blue Plus Side..." << std::endl;
        SAWP_NegativeFull_Red_BarcBot();
    } else if (selectedAuton == 1) {
        std::cout << "Running Blue Minus Side..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 2) {
        std::cout << "Running Blue Rush..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 3) {
        std::cout << "Running Blue AWP..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 4) {
        std::cout << "Running Red Plus Side..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 5) {
        std::cout << "Running Red Minus Side..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 6) {
        std::cout << "Running Red Rush..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 7) {
        std::cout << "Running Red AWP..." << std::endl;
        // Add your auton code here
    } else if (selectedAuton == 8) {
        std::cout << "Running Auton Skills..." << std::endl;
        // Add your auton code here
    } else {
        std::cout << "No valid auton selected, doing nothing." << std::endl;
    }
}

/**
 * Runs in driver control
 */
void opcontrol(){

    SAWP_NegativeFull_Red_BarcBot();

    // chassis.setPose(0, 0, 0);
    // chassis.moveToPoint(0, 24, 4000);

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

