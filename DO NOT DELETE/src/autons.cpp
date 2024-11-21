#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"


using namespace Globals;
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

void SAWP_NegativeFull_Red_BarcBot(){

chassis.setPose(-54.3, 30.8, 0);
    pros::Task Clamp(Auto_Clamp);
    // Push alliance off start line and grab alliance's preload
    IntakeMotors.move_voltage(12000);
    chassis.moveToPose(-54.3, 45, 30, 4000, {.forwards = true});
    IntakeMotors.move_voltage(0);
    //Turn to face mobile goal
    chassis.turnToHeading(300, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Move to mobile goal (drives backwards)
    chassis.moveToPoint(-24, 24, 4000, {.forwards = false});
    IntakeMotors.move_voltage(12000);
    //Turn to face first ring stack
    chassis.turnToHeading(0, 900, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    //Intake Ring
    IntakeMotors.move_voltage(12000);
    chassis.moveToPoint(-24, 41.574, 4000); 
    //Turns to face ring stack 
    // chassis.moveToPose(-48, 0, 30, 4000, {.forwards = false}); 
   
    //let go of mobile goal
    Clamp_Piston.set_value(false);
    //Moves to second mobile goal
    chassis.moveToPose(-24, -24, 300, 6000, {.forwards = false});
    //Turns to face Rings
    chassis.turnToHeading(180, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPose(-24, -48, 180, 2000);
    //Go to Elevation base
    chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -8, 4000);
}



void SoloWin_Positive_Red(){

 chassis.setPose(-52.875, 24, 270);

}


 
