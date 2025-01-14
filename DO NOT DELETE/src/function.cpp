#include "function.hpp"
#include "lemlib/chassis/odom.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"
#include "pros/misc.h"

using namespace Globals;

//Boolean vairble for sleecting what color to sort
bool sort_red = true;

void Sort(){
    pros::delay(4); //Delay to tune break point
    IntakeMotor.brake(); //Breaks intake motors
    pros::delay(1000); //Delay to control length of break period
}

void Intake(){
    while (true)
    {
        //If button R1 is being pressed, spin teh intake forwards at full speed
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        IntakeMotor.move_voltage(12000);
        }
       
        else if (!(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))) {
        IntakeMotor.move_voltage(0);
        }
        //If button "Y" is pressed: Sets intake to sort opposite color of the previous sort color
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            sort_red = !sort_red;   
        }
        if  (!SortOver){
            //If sort_red is true: Sort Red Rings
            if (sort_red & (Ring_Optical.get_hue() < 11) & (Ring_Optical.get_proximity() > 250)){
               Sort();  
            }
            //If sort_red is false: Sort Blue Rings
            else if ((!sort_red) & (Ring_Optical.get_hue() > 200) & (Ring_Optical.get_proximity() > 250)){
                Sort();
            }
        }

        // printf("my bool: %f\n", sort_red);

     pros::delay(10);
    }
}

void Clamp(){
  
    while (true){
        // If Mogo color is detected
        if ( (AutoClamp_Optical.get_proximity() > 250) & ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false) )& !ClampOver){ 
        //(AutoClamp_Optical.get_hue() >= 70)
        ClampDown = true; 
        Clamp_Piston.set_value(true);
        pros::delay(500);
        }
    }
}

void Auto_Clamp(){
  
    while (true){
        // If Mogo color is detected
        if (AutoClamp_Optical.get_hue() >= 70){
        //
        //  ClampDown = true; 
        Clamp_Piston.set_value(true);
        pros::delay(500);
        }
    }
}

bool use_macro = true;
float output;
int arm_state = 2;

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
        output = LadyBrown_pid.update(target_position*6 - WallStakeMotors.get_position_all()[0]);
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
                target_position = -19;  
                arm_state = 1;
            }
            //Load Position
            else if (arm_state == 1){
                target_position = 0;
                arm_state = 2;
            }
            //Prime Position
            else if (arm_state == 2){
                target_position = 80;
                arm_state = 3;
            }
            //Score position
            else if (arm_state == 3){
                target_position = 145;
                arm_state = 0;
            }
        }
        //Debug Print
        printf("my float: %f\n", output);
        pros::delay(10);
    }
}

