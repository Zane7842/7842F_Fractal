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
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);
}

// void SAWP_NegativeFull_Red_BarcBot(){
//   pros::Task Clamp(Auto_Clamp);
//     chassis.setPose(-54.3, 30.8, 0);
//     Clamp_Piston.set_value(false);
//     // pros::Task Sort(Intake);
//     // Push alliance off start line and grab alliance's preload
   
//     chassis.moveToPose(-54.3, 45, 30, 4000, {.forwards = true});
//     chassis.waitUntilDone();
//     IntakeMotor.move(0);
//     //Turn to face mobile goal
//     chassis.turnToHeading(290, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE,.minSpeed = 100, });
//     //Move to mobile goal (drives backwards)
//     chassis.moveToPoint(-24, 24, 4000, {.forwards = false, .maxSpeed = 40 });
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(true); 
//     IntakeMotor.move(127);
//     //Turn to face first ring stack
//     chassis.turnToHeading(0, 900, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     //Intake Ring
//     chassis.moveToPoint(-24, 41.574, 4000); 
//     //Turns to face ring stack 
//     // chassis.moveToPose(-48, 0, 30, 4000, {.forwards = false}); 
//     chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, 10, 4000);

//     //let go of mobile goal
//     // Clamp_Piston.set_value(false);
//     //Moves to second mobile goal
// //chassis.moveToPose(-24, -24, 300, 6000, {.forwards = false});
// //Turns to face Rings
// //     chassis.turnToHeading(180, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
// //     chassis.moveToPoint(-24, -48, 2000);
// //     chassis.moveToPoint(-24, -48,2000);
// //     //Go to Elevation base
// //     chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
// //     chassis.moveToPoint(-24, -10, 4000);
// }

// void SAWP_NegativeFull_Blue_BarcBot(){
//   pros::Task Clamp(Auto_Clamp);
//     chassis.setPose(54.3, 30.8, 0);
//     Clamp_Piston.set_value(false);
//     // pros::Task Sort(Intake);
//     // Push alliance off start line and grab alliance's preload
   
//     chassis.moveToPose(54.3, 45, -30, 4000, {.forwards = true});
//     chassis.waitUntilDone();
//     IntakeMotor.move(0);
//     //Turn to face mobile goal
//     chassis.turnToHeading(-290, 900, {.direction = AngularDirection::CW_CLOCKWISE,.minSpeed = 100, });
//     //Move to mobile goal (drives backwards)
//     chassis.moveToPoint(24, 24, 4000, {.forwards = false, .maxSpeed = 40 });
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(true); 
//     IntakeMotor.move(127);
//     //Turn to face first ring stack
//     chassis.turnToHeading(0, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     //Intake Ring
//     chassis.moveToPoint(24, 41.574, 4000); 
//     //Turns to face ring stack 
//     // chassis.moveToPose(-48, 0, 30, 4000, {.forwards = false}); 
//     chassis.turnToPoint(24, 0, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(24, 10, 4000);

//     //let go of mobile goal
//     // Clamp_Piston.set_value(false);
//     //Moves to second mobile goal
// //chassis.moveToPose(-24, -24, 300, 6000, {.forwards = false});
// //Turns to face Rings
// //     chassis.turnToHeading(180, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
// //     chassis.moveToPoint(-24, -48, 2000);
// //     chassis.moveToPoint(-24, -48,2000);
// //     //Go to Elevation base
// //     chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
// //     chassis.moveToPoint(-24, -10, 4000);
// }

// void SAWP_Positive_Red(){

//     chassis.setPose(-50.576, -61.137, 255);
//     pros::Task Clamp(Auto_Clamp);
//     // pros::Task Sort(Intake);
//     //Move to first mogo and pus ring stack
//     chassis.moveToPoint(-5.95, -49.194, 4000, {.forwards = false});
//     //Score preload
//     IntakeMotor.move_voltage(12000);
//     //Turn and dirve back and drop mogo
//     chassis.turnToHeading(270, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -49.194, 2000);
//     Clamp_Piston.set_value(false);
//     IntakeMotor.move_voltage(0);
//     //Turn to face second mogo
//     chassis.turnToHeading(0, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     //Move and grab second mogo
//     chassis.moveToPoint(-24, -24, 2000, {.forwards = false});
//     //Move back to middle of feild tile (lined up with red ring that was pushed)
//     chassis.moveToPoint(-24, -38, 2000);
//     //Turn to face ring that got pushed
//     chassis.turnToHeading(90, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     //Move to and intake ring that got pushed
//     IntakeMotor.move_voltage(12000);
//     chassis.moveToPoint(-5, -38, 2000);
//     //Move backwards to be in line with ring stack by allaince stake
//     chassis.moveToPoint(-48, -14, 2000, {.forwards = false});
//     //Turn to face final ring stack
//     chassis.turnToPoint(-48, 0,2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     //Dirve to and intake red and blue ring, ensure to color sort out blue.
//     chassis.moveToPoint(-31, 0.5, 4000);
// }

// void SAWP_Negative_Red_AllianceStake(){
    
//     // pros::Task Clamp(Auto_Clamp);
//     pros::Task ladyBrown(LadyBrown);
//     //Score Alliance Stake
//     chassis.setPose(-55, 16.3, 180);
//      pros::delay(6000);
//     chassis.moveToPoint(-54.3, 2, 5000);
//     chassis.turnToPoint(-69, 3, 3000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.waitUntilDone();
//     target_position = 150; //Score wall Stake
//     pros::delay(1000);

// \


//     // target_position = -19; //Default wall Stake
//     //Grab First Mobile Goal
//     // chassis.moveToPoint(-24, 24, 4000, {.forwards = false, .maxSpeed = 100});
//     // //Intake Rush Rings
//     // IntakeMotor.move_voltage(12000);
//     // chassis.turnToPoint(-3.5, 43.5, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     // chassis.moveToPose(-7.5, 40, 0, 4000, {.forwards = true});
//     // chassis.moveToPoint(-7.5, 52, 4000, {.forwards = false, .maxSpeed = 100});
//     // //Intake Ring Stack
//     // chassis.moveToPose(-15.8, 34.8, 24, 4000, {.forwards = false});
//     // chassis.turnToPoint(-24, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     // chassis.moveToPoint(-24, 48, 2000);
//     // //Move to Elevation bar
//     // chassis.waitUntilDone();
//     // target_position = 80; //Arm up to touch bar
//     // chassis.turnToPoint(-24, 0, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     // chassis.moveToPoint(-24, 11, 2000);
// }

void WACK(){
    
    // pros::Task Clamp(Auto_Clamp);
    pros::Task ladyBrown(LadyBrown);
    //Score Alliance Stake 
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 21, 4000);
    chassis.waitUntilDone();
    pros::delay(4000);
    target_position = 210; //Score wall Stake
    pros::delay(1000);
}
void Skills(){
chassis.setPose(-54.3, 0, 0);
chassis.moveToPose(-46.9, 23.5, 0, 7000);
chassis.moveToPose(-64, 64, 320, 5000);
chassis.moveToPose(-46, -23.5, 180, 7000);
chassis.moveToPose(-64, -64, 230, 5000);
chassis.moveToPose(-53, 0, 270, 5000);
pros::Task ladyBrown(LadyBrown);
    //Score Alliance Stake
chassis.waitUntilDone();
target_position = 145; //Score wall Stake




//     chassis.setPose(-55, 0, 270);
//     pros::Task Clamp(Auto_Clamp);
//     pros::Task ladyBrown(LadyBrown);
//     //Score Alliance Stake

//     // chassis.waitUntilDone();
//     target_position = 120; //Score wall Stake
//     pros::delay(500);
//     target_position = -19; //Default wall Stake
//     //Grab First Mobile goal
//     chassis.moveToPoint(-48, 0, 2000);
//     chassis.turnToPoint(-48, 24, 2000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE}); //Aim mogo
//     chassis.moveToPoint(-48, 24, 4000, {.forwards = false, .maxSpeed = 100});
//     //First Ring
//     IntakeMotor.move_voltage(12000);
//     chassis.turnToPoint(-24, 24, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, 24, 4000);
//     //Second Ring
//     chassis.turnToPoint(-24, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, 48, 4000);
//     //3rd-4th Ring
//     chassis.turnToPoint(-48, 48, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-60, 48, 4000);
//     //5th Ring
//     // chassis.turnToPoint(-47.1, 58.9, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100}); 5th ring position
//     chassis.moveToPoint(-49.4, 51.9, 4000);
//     //Put Mogo In corner
//     chassis.turnToPoint(-64, 64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(false);
//     chassis.moveToPoint(-59.3, 59.3, 4000, {.forwards = false, .maxSpeed = 100});
    
// //---------------------------------

//     //Grab Second Mogo
//     chassis.moveToPoint(-48, 48, 2000, {.forwards = false, .maxSpeed = 100});
//     chassis.turnToPoint(-64, -64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE}); //Aim for corner
//     chassis.moveToPoint(-48, -24, 2000, {.forwards = false, .maxSpeed = 100});
//     //First ring
//     chassis.turnToPoint(-24, -24, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -24, 4000);
//     //Second Ring
//     chassis.turnToPoint(-24, -48, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-24, -48, 4000);
//     //3rd-4th Ring
//     chassis.turnToPoint(-48, -48, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(-60, -48, 4000);
//     //5th Ring
//     // chassis.turnToPoint(-47.1, 58.9, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 100}); 5th ring position
//     chassis.moveToPoint(-49.4, -51.9, 4000);
//     //Put Mogo In corner
//     chassis.turnToPoint(-64, 64, 2000, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE}); //Aim for corner
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(false);
//     chassis.moveToPoint(-59.3, -59.3, 4000);

// //--------------------------------------

//     //Score Wall Stake
//     chassis.moveToPose(0, -48, 90, 4000);
//     chassis.waitUntilDone();
//     target_position = -19; //Load wall Stake
//     chassis.turnToPoint(0, -69, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 100});
//     chassis.moveToPoint(0, -57, 2000);
//     chassis.waitUntilDone();
//     target_position = 120; //Score wall Stake
//     pros::delay(500);
//     target_position = -19; //Score wall Stake
//     //Grab 3rd mobile goal
//     chassis.moveToPoint(0, -43.5, 2000, {.forwards = false, .maxSpeed = 100});
//     chassis.turnToPoint(59, -24, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
//     chassis.moveToPoint(59, -24, 4000, {.forwards = false, .maxSpeed = 100});
//     //Push 3rd goal in corner
//     chassis.turnToPoint(64, -64, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(false);
//     chassis.moveToPoint(-59.3, -59.3, 4000, {.forwards = false, .maxSpeed = 100});
//     //Grab fourth goal
//     chassis.turnToPoint(36, 36, 2000, {.forwards = false, .direction = AngularDirection::CW_CLOCKWISE});
//     chassis.moveToPoint(36, 36, 5000, {.forwards = false, .maxSpeed = 100});
//     //Intake final ring
//     chassis.turnToPoint(24, 24, 2000, {.direction = AngularDirection::CW_CLOCKWISE});
//     chassis.moveToPoint(24, 24, 5000, {.maxSpeed = 100});
//     //Push 4th mobile goal in corner
//     chassis.waitUntilDone();
//     Clamp_Piston.set_value(false);
//     chassis.moveToPoint(59.3, 59.3, 5000, {.forwards = false, .maxSpeed = 100});
}


void Skills_Simple(){
    pros::Task ladyBrown(LadyBrown);
    //Score Alliance Stake
    chassis.setPose(-55, 16.3, 180);
 target_position = 150; //Score wall Stake
}

void Simple_AWP(){
 pros::Task ladyBrown(LadyBrown);
    //Score Alliance Stake
chassis.setPose(-59.538, -13.037, 180);
target_position = 150; //Score wall Stake
chassis.moveToPoint(-56.656, -16.443, 2000, {.forwards = false});
chassis.waitUntilDone();
IntakeMotor.move(127);
chassis.turnToPoint(-23, -23, 2000, {.forwards = false});
chassis.moveToPoint(-23, -23, 4000, {.forwards = false}); 

chassis.turnToPoint(-23, -48, 2000, {.forwards = true});
chassis.moveToPoint(-23, -48, 4000);

chassis.turnToPoint(-23, -48, 2000);
chassis.waitUntilDone();
target_position = 100; //Touch Elevation Bar
chassis.moveToPoint(-23, -48, 4000);

chassis.waitUntilDone();
IntakeMotor.move(0);
}

void Simple_Auton(){
 pros::Task ladyBrown(LadyBrown);
 pros::delay(5000);
    //Score Alliance Stake
chassis.setPose(0, 0, 0);
chassis.moveToPoint(0, 4.5, 4000);
chassis.waitUntilDone();
target_position = 170; //Score wall Stake
pros::delay(2000);
chassis.moveToPoint(0, -5, 4000, {.forwards = false});
}


