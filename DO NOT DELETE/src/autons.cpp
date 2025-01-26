#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"

using namespace Globals;

void Tune_LateralPID(){
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 48, 0, 10000);
}

void Tune_AngularPID(){
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(180, 100000);
}

void Skills(){





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





