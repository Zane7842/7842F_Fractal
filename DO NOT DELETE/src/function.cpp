#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/colors.hpp"

using namespace Globals;


void Set_Hang(){
    //Enggage both PTO pistons with the drive
    PTO_LeftPiston.set_value(true); 
    PTO_RightPiston.set_value(true); 
    //Conveyor move up
    chassis.tank(127, 127); 

    if (HangConveyor_Rotation.get_position() == (27421)){
    PTO_LeftPiston.set_value(false); 
    }
}

void Start_Hang(){
    //Enggage both PTO pistons with the drive
    PTO_LeftPiston.set_value(true); 
    PTO_RightPiston.set_value(true); 

    chassis.tank(-127, -127); //Drive Backwards (conveyor down)

    for (int i = 0; i<4; i++ ){

        while (true){
            //If Crossed state, switch conveyor's direction
            if (HangConveyor_Rotation.get_position() == (16000)){  
            chassis.tank(127, 127); //Drive forward
            break;
            }
            //If Apart state, switch conveyor's direction
            if (HangConveyor_Rotation.get_position() == (27421)){  
            chassis.tank(-127, -127); //Drive forward
            break;
            }
        }      
    }

    while (true){

        if (HangConveyor_Rotation.get_position() == (15000)){
            PTO_LeftPiston.set_value(false); //Locks Hang
            chassis.tank(0,0); //Stops Hang cnoveyor
            IntakeMotors.move_voltage(12000); //Score High Stake
            pros::delay(40); //Delay to give enough time for ring to be scored
            IntakeMotors.move_voltage(0); //Stop Intake for no reason at all...
        }
    }
}

enum RingColor {   
    red = 0, 
    blue = 240, 
};

bool is_red;



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

        //Define Enum Variable
        RingColor Ring_Hue = blue;
        //Sets intake to sort red rings

        if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
                    // If this is true, ClampDown will changed to false
                    // and vice versa. 
                    is_red = !is_red;   
        //Sets intake to sort blue rings
        }

        if (is_red & (RingSorter_Optical.get_hue() < 11)){
            // pros::delay(50); //  
            IntakeMotors.brake();
            pros::delay(5); //  
        }
        else if (RingSorter_Optical.get_hue()> 200){
            // pros::delay(50); //   
            IntakeMotors.brake();
            pros::delay(10); //   
        }
    }
}


void Auto_Clamp(){
  
  while (true){
    // If Mogo color is detected
    if ((AutoClamp_Optical.get_hue() >= 70) & (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == false)){
    //
     ClampDown = true; 
    Clamp_Piston.set_value(true);
    pros::delay(500);
    }
}
}
