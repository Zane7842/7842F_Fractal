#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"

using namespace Globals;

bool is_red = false;

void Sort(){
    pros::delay(130); //
    IntakeMotors.brake();
    pros::delay(70); //  
}

void Intake(){

    while (true){

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        IntakeMotors.move_voltage(12000);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        IntakeMotors.move_voltage(-12000);
        }
        else {
        IntakeMotors.move_voltage(0);
        }

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
                    is_red = !is_red;   
        //Sets intake to sort opposite color of the previous sort color
        }
        if  (!SortOver){
            //Sort Red
            if (is_red & (Ring_Optical.get_hue() < 11) ){
               Sort();  
            }
            //Sort Blue
            else if (is_red == false & Ring_Optical.get_hue() > 200 ){
                Sort();
            }
        }
    }
}

void Clamp(){
  
    while (true){
        // If Mogo color is detected
        if ((AutoClamp_Optical.get_hue() >= 70) & ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == false) )& !ClampOver){ 
        //
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


void Load_WallStake(){
    WallStakeMotors.move_absolute(0, 127);
        //When ring is loaded, move arm out of way of intake
        if (Ring_Optical.get_hue() < 11 || Ring_Optical.get_hue() > 200) {
            pros::delay(1000);
            WallStakeMotors.move_absolute(0, 127);
        }
}

void Score_WallStake(){
    WallStakeMotors.move_absolute(0, 127);
            //Return arm to defualt position
            WallStakeMotors.move_absolute(0, 127);
}

void LadyBrown(){

    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        WallStake = !WallStake; 

    //Following if statements are embeded within the above if statmenet so that the LadyBrown arm only moves if the "" button is pressed
        if(WallStake){
            //Score on WallStake
            Score_WallStake();
        }

        if(WallStake == false){
            //Move arm to loading position
            Load_WallStake();
        }
    }
}