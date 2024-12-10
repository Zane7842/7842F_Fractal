#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"

using namespace Globals;

void Tune_LateralPID(){
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 4000);
}

void Tune_AngularPID(){
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 2000);
}

void SAWP_NegativeFull_Red_BarcBot(){
  pros::Task Clamp(Auto_Clamp);
    chassis.setPose(-54.3, 30.8, 0);
    Clamp_Piston.set_value(false);
    // pros::Task Sort(Intake);
    // Push alliance off start line and grab alliance's preload
   
    chassis.moveToPose(-54.3, 45, 30, 4000, {.forwards = true});
    chassis.waitUntilDone();
    IntakeMotors.move(0);
    //Turn to face mobile goal
    chassis.turnToHeading(290, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed = 100, });
    //Move to mobile goal (drives backwards)
    chassis.moveToPoint(-24, 24, 4000, {.forwards = false, .maxSpeed = 40 });
    chassis.waitUntilDone();
    Clamp_Piston.set_value(true); 
    IntakeMotors.move(127);
    //Turn to face first ring stack
    chassis.turnToHeading(0, 900, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    //Intake Ring
    chassis.moveToPoint(-24, 41.574, 4000); 
    //Turns to face ring stack 
    // chassis.moveToPose(-48, 0, 30, 4000, {.forwards = false}); 
    chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, 10, 4000);

    //let go of mobile goal
    // Clamp_Piston.set_value(false);
    //Moves to second mobile goal
//chassis.moveToPose(-24, -24, 300, 6000, {.forwards = false});
//Turns to face Rings
//     chassis.turnToHeading(180, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -48, 2000);
//     chassis.moveToPoint(-24, -48,2000);
//     //Go to Elevation base
//     chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -10, 4000);
}

void SAWP_NegativeFull_Blue_BarcBot(){
  pros::Task Clamp(Auto_Clamp);
    chassis.setPose(54.3, 30.8, 0);
    Clamp_Piston.set_value(false);
    // pros::Task Sort(Intake);
    // Push alliance off start line and grab alliance's preload
   
    chassis.moveToPose(54.3, 45, -30, 4000, {.forwards = true});
    chassis.waitUntilDone();
    IntakeMotors.move(0);
    //Turn to face mobile goal
    chassis.turnToHeading(-290, 900, {.direction = AngularDirection::CW_CLOCKWISE,.minSpeed = 100, });
    //Move to mobile goal (drives backwards)
    chassis.moveToPoint(24, 24, 4000, {.forwards = false, .maxSpeed = 40 });
    chassis.waitUntilDone();
    Clamp_Piston.set_value(true); 
    IntakeMotors.move(127);
    //Turn to face first ring stack
    chassis.turnToHeading(0, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Intake Ring
    chassis.moveToPoint(24, 41.574, 4000); 
    //Turns to face ring stack 
    // chassis.moveToPose(-48, 0, 30, 4000, {.forwards = false}); 
    chassis.turnToPoint(24, 0, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(24, 10, 4000);

    //let go of mobile goal
    // Clamp_Piston.set_value(false);
    //Moves to second mobile goal
//chassis.moveToPose(-24, -24, 300, 6000, {.forwards = false});
//Turns to face Rings
//     chassis.turnToHeading(180, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -48, 2000);
//     chassis.moveToPoint(-24, -48,2000);
//     //Go to Elevation base
//     chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -10, 4000);
}

void SAWP_Positive_Red(){

    chassis.setPose(-50.576, -61.137, 255);
    pros::Task Clamp(Auto_Clamp);
    // pros::Task Sort(Intake);
    //Move to first mogo and pus ring stack
    chassis.moveToPoint(-5.95, -49.194, 4000, {.forwards = false});
    //Score preload
    IntakeMotors.move_voltage(12000);
    //Turn and dirve back and drop mogo
    chassis.turnToHeading(270, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -49.194, 2000);
    Clamp_Piston.set_value(false);
    IntakeMotors.move_voltage(0);
    //Turn to face second mogo
    chassis.turnToHeading(0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Move and grab second mogo
    chassis.moveToPoint(-24, -24, 2000, {.forwards = false});
    //Move back to middle of feild tile (lined up with red ring that was pushed)
    chassis.moveToPoint(-24, -38, 2000);
    //Turn to face ring that got pushed
    chassis.turnToHeading(90, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Move to and intake ring that got pushed
    IntakeMotors.move_voltage(12000);
    chassis.moveToPoint(-5, -38, 2000);
    //Move backwards to be in line with ring stack by allaince stake
    chassis.moveToPoint(-48, -14, 2000, {.forwards = false});
    //Turn to face final ring stack
    chassis.turnToPoint(-48, 0,2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    //Dirve to and intake red and blue ring, ensure to color sort out blue.
    chassis.moveToPoint(-31, 0.5, 4000);
}

void SAWP_Negative_Red_AllianceStake(){
    
    pros::Task Clamp(Auto_Clamp);
    //Score Alliance Stake
    chassis.setPose(-55, 16.3, 180);
    chassis.moveToPoint(-54.3, 7, 4000);
    chassis.turnToPoint(-69, 0, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.waitUntilDone();
    Score_WallStake();
    pros::delay(500);
    //Grab First Mobile Goal
    chassis.moveToPoint(-24, 24, 4000, {.forwards = false, .maxSpeed = 100});
    //Intake Rush Rings
    IntakeMotors.move_voltage(12000);
    chassis.turnToPoint(-3.5, 43.5, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPose(-7.5, 40, 0, 4000, {.forwards = true});
    chassis.moveToPoint(-7.5, 52, 4000, {.forwards = false, .maxSpeed = 100});
    //Intake Ring Stack
    chassis.moveToPose(-15.8, 34.8, 24, 4000, {.forwards = false});
    chassis.turnToPoint(-24, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, 48, 2000);
    //Move to Elevation bar
    chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, 11, 2000);
}

void Skills(){
    pros::Task Clamp(Auto_Clamp);
    //Score Alliance Stake
    chassis.setPose(-55, 0, 270);
    //Grab First Mobile goal
    chassis.moveToPoint(-48, 0, 2000);
    chassis.turnToPoint(-48, 24, 2000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE}); //Aim mogo
    chassis.moveToPoint(-48, 24, 4000, {.forwards = false, .maxSpeed = 100});
    //First Ring
    IntakeMotors.move_voltage(12000);
    chassis.turnToPoint(-24, 24, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, 24, 4000);
    //Second Ring
    chassis.turnToPoint(-24, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, 48, 4000);
    //3rd-4th Ring
    chassis.turnToPoint(-48, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-60, 48, 4000);
    //5th Ring
    // chassis.turnToPoint(-47.1, 58.9, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100}); 5th ring position
    chassis.moveToPoint(-49.4, 51.9, 4000);
    //Put Mogo In corner
    chassis.turnToPoint(-64, 64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    Clamp_Piston.set_value(false);
    chassis.moveToPoint(-59.3, 59.3, 4000, {.forwards = false, .maxSpeed = 100});
    
//---------------------------------

    //Grab Second Mogo
    chassis.moveToPoint(-48, 48, 2000, {.forwards = false, .maxSpeed = 100});
    chassis.turnToPoint(-64, -64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE}); //Aim for corner
    chassis.moveToPoint(-48, -24, 2000, {.forwards = false, .maxSpeed = 100});
    //First ring
    chassis.turnToPoint(-24, -24, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -24, 4000);
    //Second Ring
    chassis.turnToPoint(-24, -48, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-24, -48, 4000);
    //3rd-4th Ring
    chassis.turnToPoint(-48, -48, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(-60, -48, 4000);
    //5th Ring
    // chassis.turnToPoint(-47.1, 58.9, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100}); 5th ring position
    chassis.moveToPoint(-49.4, -51.9, 4000);
    //Put Mogo In corner
    chassis.turnToPoint(-64, 64, 2000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE}); //Aim for corner
    chassis.waitUntilDone();
    Clamp_Piston.set_value(false);
    chassis.moveToPoint(-59.3, -59.3, 4000);

//--------------------------------------

    //Score Wall Stake
    chassis.moveToPose(0, -48, 90, 4000);
    chassis.waitUntilDone();
    Load_WallStake();
    chassis.turnToPoint(0, -69, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
    chassis.moveToPoint(0, -57, 2000);
    chassis.waitUntilDone();
    Score_WallStake();
    //Grab 3rd mobile goal
    chassis.moveToPoint(0, -43.5, 2000, {.forwards = false, .maxSpeed = 100});
    chassis.turnToPoint(59, -24, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(59, -24, 4000, {.forwards = false, .maxSpeed = 100});
    //Push 3rd goal in corner
    chassis.turnToPoint(64, -64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    Clamp_Piston.set_value(false);
    chassis.moveToPoint(-59.3, -59.3, 4000, {.forwards = false, .maxSpeed = 100});
    //Grab fourth goal
    chassis.turnToPoint(36, 36, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(36, 36, 5000, {.forwards = false, .maxSpeed = 100});
    //Intake final ring
    chassis.turnToPoint(24, 24, 2000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(24, 24, 5000, {.maxSpeed = 100});
    //Push 4th mobile goal in corner
    chassis.waitUntilDone();
    Clamp_Piston.set_value(false);
    chassis.moveToPoint(59.3, 59.3, 5000, {.forwards = false, .maxSpeed = 100});
}
