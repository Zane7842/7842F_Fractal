#include "function.hpp"
#include "lemlib/chassis/odom.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"
#include "pros/misc.h"

using namespace Globals;

//Boolean vairble for sleecting what color to sort
bool sort_red = false;
bool is_red = true;

void Match_Sort(){
    // if(IntakeMotor.get_actual_velocity()>140){
    // Initial_delay = 7;
    // }
    // else if(IntakeMotor.get_actual_velocity()<140){
    // Initial_delay = 10;
    // }
    // Initial_delay = 980/IntakeMotor.get_actual_velocity()/(2)-7;
    pros::delay(65); //Delay to tune break point
    IntakeMotor.move_voltage(-12000);
    pros::delay(100); //Delay to control length of break period
    target_position = -19;
    IntakeMotor.move_voltage(12000);
}

void Intake(){
    while (true){
        is_red = true;
        //If button R1 is being pressed, spin teh intake forwards at full speed
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        IntakeMotor.move_voltage(12000);
        }
        else if (!(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
        IntakeMotor.move_voltage(0);
        }
        //If button "Y" is pressed: Sets intake to sort opposite color of the previous sort color
        // if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        //     sort_red = !sort_red;   
        // }

        //     if ((Ring_Optical.get_hue()<13)){
        //         is_red = true;
        //     }
        //     if ((Ring_Optical.get_hue() < 260) & (Ring_Optical.get_hue() > 215)){
        //         is_red = false;
        //     }
            // if(get_opticalColor() == 3){
            //     //Sort Blue
            //     if ((Ring_Distance.get() < 25)){
            //     target_position = 40;  
            //     } 
            //     if ((Ring_Distance.get() < 10)){
            //     Match_Sort();  
            //     }   
            // }

            // if (target_position > 0 & target_position < 6){
            //     if (IntakeMotor.get)
            // }

    // printf("my int: %d\n", Initial_delay);

    pros::delay(11);
    }
}

void Auton_Intake(){
    is_red = true;
    while (true){
        if(true){
            //Sort Blue
            if ((Ring_Distance.get() < 25)){
            target_position = 40;  
            } 
            if ((Ring_Distance.get() < 10)){
            Match_Sort();  
            }   
        }
    }

    // printf("my int: %d\n", Initial_delay);

    pros::delay(11);
}

void Auton_StopIntake(){
    while (true){
        IntakeMotor.move_voltage(12000);
        if (get_opticalColor() == desired_ring){ 
               IntakeMotor.brake();
               pros::delay(2500);
               return;
        } 
    }
}

// Get color without delay
static int get_opticalColor() {
    double hue = Ring_Optical.get_hue();
    if (Ring_Optical.get_proximity() < 100) return 1; //none //IMPORTANT: was set to 100 for autons
    if (hue < 10 || hue > 355) return 2; //red
    if (hue > 200 && hue < 240) return 3; //blue
    return 1;
}

void Clamp(){
  
    while (true){
        // If Mogo color is detected
        if ( (AutoClamp_Optical.get_proximity() > 250) & ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false) )){ 
        //(AutoClamp_Optical.get_hue() >= 70)
        ClampDown = true; 
        Clamp_Piston.set_value(ClampDown);
        pros::delay(500);
        }
    }
}

void Auto_Clamp(){
  
    while (true){
         // If Mogo color is detected
        if ( (AutoClamp_Optical.get_proximity() > 250) & ((ClampUp == false) )){ 
        //(AutoClamp_Optical.get_hue() >= 70)
        ClampDown = true; 
        Clamp_Piston.set_value(ClampDown);
        pros::delay(500);
        }
    }

}

bool use_macro = true;
float output;
int arm_state = 1;

void LadyBrown(){
    while (true) {
        //Manual control
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        use_macro = false;
        WallStakeMotors.move_voltage(6000);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        use_macro = false;
        WallStakeMotors.move_voltage(-6000);
        }
        else if (!use_macro) {
        WallStakeMotors.move_voltage(0);
        }
        else {
            // If we are using the PID controller (not manually controlling the arm),
            // then we use the output of the PID controller as our input voltage to
            // the motor.
          output = LadyBrown_pid.update(target_position*3 - WallStakeMotors.get_position_all()[0]);
        // WallStakeMotors.move_absolute(target_position * 5, 127);
        WallStakeMotors.move(output);
        }

        //State Machine
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            if (!use_macro) {
            // User was controlling the arm manually, but pressed B, so we switch
            // back into macro mode.
            use_macro = true;
            }
            //Out of way position
            if (arm_state == 0){
                target_position = -23.25 + start_offset;  
                arm_state = 1;
            }
            //Load Position
            else if (arm_state == 1){
                target_position = 4 + start_offset;
                arm_state = 2;
            }
             //Prime Position
            else if (arm_state == 2){
                target_position =110 + start_offset; //110 for passive score
                arm_state = 3;
            }
           //Score position
            else if (arm_state == 3){
                target_position = 145 + start_offset;
                arm_state = 0;
            }
        }
        // //Debug Print
        // printf("my float: %f\n", output);
        pros::delay(10);
    }
}

void print_odom(){
    while (true){

        printf("X: %.2f, Y: %.2f, Theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(10);
    }
}



