#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"

using namespace Globals;

void Tune_LateralPID(){
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 23, 0, 10000);
    // chassis.turnToHeading(180, 100000);
    // chassis.moveToPose(0, 0, 0, 10000);
    // chassis.turnToHeading(0, 100000);
    // chassis.moveToPose(0, 48, 0, 10000);
    // chassis.turnToHeading(0, 100000);
    // chassis.moveToPose(0, 48, 0, 10000);

}

void Tune_AngularPID(){
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(118, 100000);
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

void SAWP(){
    ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    pros::Task ladyBrown(LadyBrown);
//times movemnets by 1.09375
    chassis.setPose(0, 0, 0);
    //Score Alliance Stake
    chassis.moveToPose(0, 6.5, 0, 800);
    chassis.turnToPoint(14, 10.25, 600);
    chassis.waitUntilDone();
    target_position = 155;
    pros::delay(600);
    //Grab first mogo
    ClampUp = false;
    chassis.moveToPose(-19.27, -6.445, 62.2, 1000, {.forwards = false}); //25
    chassis.waitUntil(5);
    target_position = -19;
    chassis.moveToPose(-31.75, -13.29, 62.2, 1000, {.forwards = false,.maxSpeed = 50}); //25
    //Intake far rings
    chassis.turnToHeading(234.2, 700, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    IntakeMotor.move_voltage(12000);
    chassis.moveToPose(-50.5, -29.29, 180, 2000, {.forwards = true}); //25
    chassis.moveToPose(-50.5, -39.5, 180, 2000);
    //Intake close ring
    chassis.moveToPose(-45.18, -22.7, 210, 2000, {.forwards = false});
    chassis.turnToPoint(-37.7, -34.7, 1000);
    chassis.moveToPoint(-37.7, -34.7, 2000);
    //Intake/sort middle ring
    chassis.turnToPoint(-6, -14, 1000);
    chassis.waitUntilDone();
    pros::Task RingSort(Auton_StopIntake);
    chassis.moveToPoint(-5, -14, 4000);
    chassis.turnToPoint(-6, 7, 1000);
    // chassis.waitUntilDone();
    // pros::Task Sort(Auton_Intake);
    // ClampDown = true; 
    // Clamp_Piston.set_value(ClampDown);
    // chassis.moveToPoint(-10.5, 7, 1000);
    
    }


void SimpleSAWP(){
    ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    pros::Task ladyBrown(LadyBrown);

    //62 degrees with 1 ring constants
    angular_controller.kP = 4.53;
    angular_controller.kI = 0.0029;
    angular_controller.kD = 43;
    //8.5" and 23" lateral (no goal)
    linear_controller.kP = 31;
    linear_controller.kI = 0.0000;
    linear_controller.kD = 213;

        chassis.setPose(-14.5, -15.25, 0);

        //Score Alliance Stake
        chassis.moveToPose(-14.5, -8.25, 0, 1000);
        chassis.turnToPoint(0, 0, 1000);
        chassis.waitUntilDone();
        target_position = 155;
    pros::delay(600);

        //Grab first mogo
    ClampUp = false;
        chassis.moveToPose(-35, -17.3, 62.2, 2000, {.forwards = false}); // 
        chassis.waitUntil(5);
    target_position = -19;
        chassis.moveToPose(-48, -24, 62.2, 5000, {.forwards = false,.maxSpeed = 50}); 
        chassis.waitUntilDone();

    //115 degree with an empty mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Intake first ring
    IntakeMotor.move_voltage(12000);
        chassis.turnToPoint(-47.1, -47.1, 1000);
        chassis.moveToPose(-45.25, -41.5, 180, 2000);

        //Sort+Store second ring 
        chassis.turnToPoint(-24.8, 3.7, 1000);
        chassis.waitUntilDone();
    pros::Task RingSort(Auton_StopIntake); 
        chassis.moveToPose(-18.38, 23.61, 21, 4000, {.maxSpeed = 50}); 

        //Grab second goal and score second ring
        chassis.turnToPoint(-47.23, 23.61, 1000,{.forwards = false});
        chassis.moveToPose(-47.23, 23.61, 90, 2000,{.forwards = false, .maxSpeed = 50});
         chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000);
        //Intake last ring
        chassis.turnToPoint(-47.3, 47, 1000);
        chassis.moveToPose(-47.3, 47, 0, 2000);

        //Touch Ladder
    //     chassis.turnToPoint(-48.26, 21.56, 1000);
    //     chassis.moveToPose(-48.26, 21.56, 242, 2000);
    //     chassis.waitUntil(5);
    // target_position = 105;
    
    //115 degree with an empty mobile goal constant
    // angular_controller.kP = 4.52;
    // angular_controller.kI = 0.0000;
    // angular_controller.kD = 47;
}
// 14.68, 22.79 (away from 0, 0)
//-14.91, -23.07


