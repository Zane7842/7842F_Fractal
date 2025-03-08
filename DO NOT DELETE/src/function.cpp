#include "function.hpp"
#include "lemlib/chassis/odom.hpp"
#include "liblvgl/misc/lv_anim.h"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"

using namespace Globals;

//Boolean vairble for sleecting what color to sort
bool sort_red = false;
bool is_red = true;

//496 --> 540
bool sort = false;

void Sort(){
    while (pros::competition::is_autonomous()){
        is_red = true;
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
                IntakeMotor.move_voltage(12000);
                // IntakeMotor.move_voltage(12000);
                sort = false;
            }
        }


    printf("my int: %d\n", get_opticalColor());

    pros::delay(11);
    }
}

void Auton_StopIntake(){
    while (pros::competition::is_autonomous()){  
        IntakeMotor.move_voltage(10000);
        if (get_opticalColor() == desired_ring){ 
               IntakeMotor.brake();
               pros::delay(2500);
               return;
        } 
    }
}

// Get color without delay
int get_opticalColor() {
    double hue = Ring_Optical.get_hue();
    if (Ring_Optical.get_proximity() < 100) return 3; //none //IMPORTANT: was set to 100 for autons
    if (hue < 10 || hue > 355) return 0; //red
    if (hue > 200 && hue < 240) return 1; //blue
    return 3;
}

void Clamp(){
    while (true){
        // If Mogo color is detected
        if ( (AutoClamp_Distance.get() < 12) & ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false) )){ 
        //(AutoClamp_Optical.get_hue() >= 70)
        ClampDown = true; 
        Clamp_Piston.set_value(ClampDown);
        pros::delay(500);
        }
    }
}

void Auto_Clamp(){
    //will only run in auton m
    while (pros::competition::is_autonomous()){
        //  If Mogo color is detected
       if ((AutoClamp_Distance.get() < 12) & ((ClampUp == false))){ 
       ClampDown = true; 
       Clamp_Piston.set_value(ClampDown);
        pros::delay(500); //was 500
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
                target_position = 6 + start_offset;
                arm_state = 2;
            }
             //Prime Position
            else if (arm_state == 2){
                target_position =30 + start_offset; //110 for passive score
                arm_state = 3;
            }
           //Score position
            else if (arm_state == 3){
                target_position = 152 + start_offset;
                arm_state = 0;
            }
        }
        // //Debug Print
        // printf("my float: %f\n", output);
        pros::delay(10);
    }
}

void Auton_LadyBrown(){

    while (pros::competition::is_autonomous()){
        output = LadyBrown_pid.update(target_position*3 - WallStakeMotors.get_position_all()[0]);
        // WallStakeMotors.move_absolute(target_position * 5, 127);
        WallStakeMotors.move(output);

    pros::delay(10);
    }

}

void print_odom(){
    while (true){

        printf("X: %.2f, Y: %.2f, Theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(10);
    }
}



