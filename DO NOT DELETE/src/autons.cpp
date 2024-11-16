#include "autons.hpp"
#include "main.h"

void SAWP_Negative_Red(){

 chassis.setPose(-52.875, 24, 270);
    // //Grab first mogo
    chassis.moveToPose(-32.875, 24, 270, 1000, {.forwards = false});
    chassis.turnToHeading(80, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    IntakeMotors.move_voltage(12000);
    chassis.moveToPose(-7.5, 40, 40, 1500);

    chassis.moveToPose(-14, 60, 0, 3000, {.forwards = true});
    chassis.moveToPose(-40, 0, 0, 4000, {.forwards = false});

}

void SAWP_Negative_Red_BarcBot(){

chassis.setPose(-54.3, 30.8, 0);
    Task Clamp(Auto_Clamp);
    // Push alliance off start line and grab alliance's preload
    IntakeMotors.move_voltage(12000);
    chassis.moveToPose(-54.3, 41, 40, 1000, {.forwards = true});
    IntakeMotors.move_voltage(0);
    //Turn to face mobile goal
    chassis.turnToHeading(300, 900, {.direction = AngularDirection::CCCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Move to mobile goal (drives backwards)
    chassis.moveToPose(-24, 24, 300, 2000, {.forwards = false});
    if (Clamp_Piston.get() == true){
        IntakeMotors.move_voltage(12000);
    }
    //Turn to face first ring stack
    chassis.turnToHeading(0, 900, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    //Intake Ring
    IntakeMotors.move_voltage(12000);
    chassis.moveToPose(-24, 41.574, 0, 2000); 
    //Turns to face ring stack 
    chassis.turnToPoint(-48, 0, 900, {.direction = AngularDirection::CCCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-48, 0, 2000, );
    //let go of mobile goal
    Clamp_Piston.set_value(false);
    //Moves to second mobile goal
    chassis.moveToPose(-24, -24, 300, 4000, {.forwards = false});
    //Turns to face Rings
    chassis.turnToPoint(-24, -48, 1000, {.direction = AngularDirection::CCCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -24, 2000);
    //Go to Elevation base
    chassis.turnToPoint(-24, 0, 1000, {.direction = AngularDirection::CCCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -8, 4000);
}



void SoloWin_Positive_Red(){

 chassis.setPose(-52.875, 24, 270);
    // //Grab first mogo
    chassis.moveToPose(-32.875, 24, 270, 1000, {.forwards = false});
    chassis.turnToHeading(80, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    IntakeMotors.move_voltage(12000);
    chassis.moveToPose(-7.5, 40, 40, 1500);

    chassis.moveToPose(-14, 60, 0, 3000, {.forwards = true});
    chassis.moveToPose(-40, 0, 0, 4000, {.forwards = false});

}


 
