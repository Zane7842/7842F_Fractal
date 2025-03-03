#include "function.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"

using namespace Globals;

void Tune_LateralPID(){
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 48, 0, 10000, {.maxSpeed = 80});
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
    // turn to face heading 180 with a very long timeout
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

void SimpleSAWP_red(){
//Note: Alliance Stake is 0, 0
    ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    // pros::Task ladyBrown(LadyBrown);

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
        chassis.moveToPose(-14.5, -8.25, 0, 550);
        chassis.turnToPoint(0, 0, 500);
        chassis.waitUntilDone();
        ClampUp = false;
        target_position = 180;
    pros::delay(500);
        //Grab first mogo
        chassis.moveToPose(-35, -17.3, 62.2, 1100, {.forwards = false, .minSpeed=79, .earlyExitRange=8.5}); // 1400
        chassis.waitUntil(5);
    target_position = -20;
        chassis.moveToPose(-48, -24, 62.2, 500, {.forwards = false,.maxSpeed = 75}); 
        chassis.waitUntilDone();

    //115 degree with an empty mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Intake first ring
    IntakeMotor.move_voltage(12000);
        chassis.turnToPoint(-47.1, -47.1, 800);
        chassis.moveToPose(-45.25, -40.57, 180, 1200);
        chassis.waitUntilDone();

    //90 degree with a mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0021;
    angular_controller.kD = 47;

        //Intake far rings
        chassis.turnToPoint(-67.1, -43.24, 500);
        chassis.moveToPose(-60, -43.24, 270, 900);
        chassis.moveToPose(-45.25, -43.24, 270, 900, {.forwards = false});
        chassis.waitUntilDone();

    //120 degree with a mobile goal + 2 rings constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Sort+Store second ring 
        chassis.turnToPoint(-24.8, 3.7, 600);
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000); //addee explicit intake move on top of function.
        // desired_ring = 2;//Red ring is desired
    // pros::Task RingSort(Auton_StopIntake); 
        chassis.moveToPose(-32.75, -10.15, 21, 1200, {.minSpeed=80, .earlyExitRange=8});
        chassis.waitUntil(25);
        ClampDown = false; 
        ClampUp = true;
        Clamp_Piston.set_value(ClampDown); //Drops first mogo
        chassis.moveToPose(-18.38, 23.61, 21, 950, {.maxSpeed = 80}); 

        //Grab second goal and score second ring
        chassis.turnToPoint(-47.23, 23.61, 550,{.forwards = false});
        chassis.waitUntilDone();
        ClampUp = false;
        chassis.moveToPose(-49.23, 23.61, 90, 1650,{.forwards = false, .maxSpeed = 55});
        chassis.waitUntilDone();

    //90 degree with a mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0021;
    angular_controller.kD = 47;

        //Intake last ring
        chassis.turnToPoint(-49.92, 47, 300);
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000);
        chassis.moveToPose(-49.92, 39.9, 0, 800, {.minSpeed=105, .earlyExitRange=8});
        // Touch Ladder
        // chassis.turnToPoint(-48.26, 21.56, 500);
        chassis.moveToPose(-48.26, 21.56, 242, 2000,{.lead = 0, .minSpeed=127});
        chassis.waitUntil(3);
    target_position = 147;
}
void SimpleSAWP_blue(){
//Note: Alliance Stake is 0, 0
    ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    // pros::Task ladyBrown(LadyBrown);

    //62 degrees with 1 ring constants
    angular_controller.kP = 4.53;
    angular_controller.kI = 0.0029;
    angular_controller.kD = 43;
    //8.5" and 23" lateral (no goal)
    linear_controller.kP = 31;
    linear_controller.kI = 0.0000;
    linear_controller.kD = 213;

        chassis.setPose(14.5, -15.25, 0); //was -14.5

        //Score Alliance Stake
        chassis.moveToPose(14.5, -8.25, 0, 550); //was -14.5
        chassis.turnToPoint(0, 0, 500);
        chassis.waitUntilDone();
        target_position = 180;
    pros::delay(500);

        //Grab first mogo
    ClampUp = false;
        chassis.moveToPose(35, -17.3, -62.2, 1100, {.forwards = false, .minSpeed=79, .earlyExitRange=8.5}); //was -35, 62.2
        chassis.waitUntil(5);
    target_position = -20;
        chassis.moveToPose(48, -24, -62.2, 500, {.forwards = false,.maxSpeed = 75}); //was -48, 62.2
        chassis.waitUntilDone();

    //115 degree with an empty mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Intake first ring
    IntakeMotor.move_voltage(12000);
        chassis.turnToPoint(47.1, -47.1, 800);//was -47.1
        chassis.moveToPose(45.25, -40.57, -180, 1200); //was -45.25
        chassis.waitUntilDone();

    //90 degree with a mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0021;
    angular_controller.kD = 47;

        //Intake far rings
        chassis.turnToPoint(67.1, -43.24, 500); //was -67.1
        chassis.moveToPose(60, -43.24, -270, 900); //was -60, 270
        chassis.moveToPose(45.25, -43.24, -270, 900, {.forwards = false}); //was -45.25, 270
        chassis.waitUntilDone();

    //120 degree with a mobile goal + 2 rings constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Sort+Store second ring 
        chassis.turnToPoint(24.8, 3.7, 600); //was-24.8
        chassis.waitUntilDone();
        desired_ring = 3; //Blue ring is desired
    pros::Task RingSort(Auton_StopIntake); 
        chassis.moveToPose(32.75, -10.15, -21, 1200, {.minSpeed=80, .earlyExitRange=8}); //was -32.75, 21
        chassis.waitUntil(25);
        ClampDown = false; 
        ClampUp = true;
        Clamp_Piston.set_value(ClampDown); //Drops first mogo
        chassis.moveToPose(18.38, 23.61, -21, 950, {.maxSpeed = 80}); //was -18.38, 21

        //Grab second goal and score second ring
        chassis.turnToPoint(47.23, 23.61, 550,{.forwards = false}); //was -47.23
        chassis.waitUntilDone();
        ClampUp = false;
        chassis.moveToPose(49.23, 23.61, -90, 1550,{.forwards = false, .maxSpeed = 55}); //was -49.23, 90
        chassis.waitUntilDone();

    //90 degree with a mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0021;
    angular_controller.kD = 47;

        //Intake last ring
        chassis.turnToPoint(49.92, 47, 300); //was -49.92
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000);
        chassis.moveToPose(49.92, 39.9, 0, 700, {.minSpeed=105, .earlyExitRange=8}); //was-49.92, 0
        // Touch Ladder
        // chassis.turnToPoint(-48.26, 21.56, 500);
        chassis.moveToPose(48.26, 21.56, -242, 2000,{.lead = 0, .minSpeed=127}); //was -48.26, 242
        chassis.waitUntil(3);
    target_position = 147;
}


void Positive_red_negative_blue(){

     ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    ClampUp = true;
         Clamp_Piston.set_value(false);

    chassis.setPose(14.5, -18.23, -35);
    pros::delay(2000);
    //score alliance stake
    target_position = 165;
    pros::delay(500);
    //align to get ring stack
    chassis.moveToPose(33.5, -29, 0, 2000,{.forwards = false}); // subject to change
    chassis.moveToPose(34, -20, 0, 1700); // subject to change
    chassis.waitUntil(7);
// LeftDoinker_Down = true; 
LeftDoinker_Piston.set_value(true);
    chassis.moveToPose(34, -29, 0, 1000,{.forwards = false}); // subject to change
    chassis.waitUntil(5);
// LeftDoinker_Down = false; 
LeftDoinker_Piston.set_value(false);
pros::Task Intake(Auton_StopIntake);
    //Intake ring
    chassis.moveToPose(28.10, -18.125, -24.86, 2000); // subject to change
    chassis.waitUntilDone();
    //grab mogo
    ClampUp = false;
    chassis.moveToPose(49, -28.97, -60, 2500,{.forwards = false, .maxSpeed = 60}); //
    chassis.waitUntilDone();
    IntakeMotor.move_voltage(12000);
    chassis.turnToPoint(52.52, -54.66, 1000,{.maxSpeed = 127, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPose(52.52, -54.66, 180, 2000,{.maxSpeed = 127, .minSpeed = 10, .earlyExitRange = 1});


    // chassis.moveToPose(51.13, -30.13, -120, 2000, {.forwards = false, .maxSpeed = 80});


    // chassis.moveToPose(28.05, -21.28, 0, 2000); //straight on for stop intake function

    // chassis.moveToPoint(26.68, -34.87, 2000, {.forwards = false,.minSpeed = 1});
    // chassis.turnToPoint(28.4, -3.8, 2000, {.minSpeed = 1});

    //Intake ring stack
    // Auton_StopIntake();
    // chassis.moveToPoint(28.4, -3.8, 2000, {.minSpeed = 1});


    // //Grab mogo
    // ClampUp = false;
    // chassis.moveToPose(55.26, -22, -120, 2000, {.forwards = false, .maxSpeed = 80});
    // chassis.waitUntilDone();
    // IntakeMotor.move_voltage(12000);
    // chassis.moveToPose(47.95, -41.51, -180, 3000, {.maxSpeed = 80});
    // chassis.moveToPose(47.95, -19.5, -180, 1500, {.forwards = false,.maxSpeed = 80});

    //  // corner
    //     chassis.moveToPose(21.17, -58.3, -90, 2000, {.lead = 0.2});//prep
    //     chassis.moveToPose(7.75, -59.69, -90, 2000, {.maxSpeed = 55});//inatke

    // // chassis.turnToHeading(0, 1000);
    // // chassis.waitUntilDone();
    // // // target_position = 110;
    // // //  chassis.moveToPose(47.95, -3, -180, 2000, {.maxSpeed = 80});
    // //corner
    // // chassis.turnToHeading(-135, 2000);
    // // chassis.moveToPoint(12, -65.47, 4000, {.maxSpeed = 70});
}

void Positive_blue_negative_red(){

     ClampUp = true; //Ensures Clamp is up
    pros::Task Clamp(Auto_Clamp);
    ClampUp = true;
         Clamp_Piston.set_value(false);

    chassis.setPose(-14.5, -18.23, 35);
    pros::delay(2000);
    target_position = 185;
    pros::delay(500);
    ClampUp = false;
    chassis.moveToPose(-55.26, -22, 120, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    IntakeMotor.move_voltage(12000);
    chassis.moveToPose(-47.95, -41.51, 180, 3000, {.maxSpeed = 80});
    chassis.moveToPose(-47.95, -19.5, 180, 1500, {.forwards = false,.maxSpeed = 80});
    // chassis.turnToHeading(0, 1000);
    // chassis.waitUntilDone();
    // target_position = 110;
    //  chassis.moveToPose(-47.95, -3, 180, 2000, {.maxSpeed = 80});
    // corner
        // chassis.moveToPose(-21.17, -58.3, 90, 2000, {.lead = 0.2});//prep
        // chassis.moveToPose(-7.75, -60.69, 90, 2000, {.maxSpeed = 55});//inatke

    // chassis.turnToHeading(-135, 2000);
    // chassis.moveToPose(12, -65.47, 4000, {.maxSpeed = 70});
}

// void ColorSort_test(){


// }