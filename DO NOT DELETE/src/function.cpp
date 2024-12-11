#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"
#include "pros/misc.h"

using namespace Globals;

//Boolean vairble for sleecting what color to sort
bool sort_red = false;

void Sort(){
    pros::delay(130); //Delay to tune break point
    IntakeMotors.brake(); //Breaks intake motors
    pros::delay(70); //Delay to control length of break period
}

void Intake(){
    while (true){
        //If button R1 is being pressed, spin teh intake forwards at full speed
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        IntakeMotors.move_voltage(12000);
        }
        //If button R1 is being pressed, spin the intake backwards at full speed
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        IntakeMotors.move_voltage(-12000);
        }
        else {
        IntakeMotors.move_voltage(0);
        }
        //If button "Y" is pressed: Sets intake to sort opposite color of the previous sort color
        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            sort_red = !sort_red;   
        }
        if  (!SortOver){
            //If sort_red is true: Sort Red Rings
            if (sort_red & (Ring_Optical.get_hue() < 11) ){
               Sort();  
            }
            //If sort_red is false: Sort Blue Rings
            else if ((!sort_red) & (Ring_Optical.get_hue() > 200) ){
                Sort();
            }
        }
    }
}

void Clamp(){
  
    while (true){
        // If Mogo color is detected
        if ((AutoClamp_Optical.get_hue() >= 70) & ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false) )& !ClampOver){ 
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
    WallStakeMotors.move_absolute(0, 100);
        //When ring is loaded, move arm out of way of intake
        if (Ring_Optical.get_hue() < 11 || Ring_Optical.get_hue() > 200) {
            pros::delay(1000);
            WallStakeMotors.move_absolute(80, 127);
        }
}

void Score_WallStake(){
    WallStakeMotors.move_absolute(120, 127);
            //Return arm to defualt position
    WallStakeMotors.move_absolute(-19, 127);
}

// void LadyBrown(){
//     while (true){
//         if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
//             WallStake = !WallStake; 
//         }
//         if(WallStake){
//         //Score Wall Stake
//         WallStakeMotors.move_absolute(120, 127);
//         pros::delay(2000);
//         //Return arm to defualt position
//         WallStakeMotors.move_absolute(-19, 127);
//         }

//         if(WallStake == false){
//             //Move arm to loading position
//             WallStakeMotors.move_absolute(0, 127);
//         }
//     }
// }

int arm_state = 0;
bool use_macro = true;

void arm(){
    //Out of way position
    if (arm_state == 0){
        WallStakeMotors.move_absolute(-19, 127);
        arm_state = 1;
        return;
    }
    //Load Position
     if (arm_state == 1){
        WallStakeMotors.move_absolute(0, 127);
        arm_state = 2;
        return;
    }
    //Prime Position
     if (arm_state == 2){
        WallStakeMotors.move_absolute(80, 127);
        arm_state = 3;
        return;
    }
    //Score position
    if (arm_state == 3){
        WallStakeMotors.move_absolute(120, 127);
        arm_state = 0;
        return;
    }
}

void LadyBrown(){

    while (true) {

        //Manual control
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        use_macro = false;
        WallStakeMotors.move_voltage(12000);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        use_macro = false;
        WallStakeMotors.move_voltage(-12000);
        }
        else if (!use_macro) {
        WallStakeMotors.move_voltage(0);
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            if (!use_macro) {
            // User was controlling the arm manually, but pressed B, so we switch
            // back into macro mode.
            use_macro = true;
            arm();
            }
        }
    }
}

