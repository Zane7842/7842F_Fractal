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
    chassis.turnToHeading(123, 100000);
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


void SimpleSAWP_red(){
//Note: Alliance Stake is 0, 0
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
        chassis.moveToPose(-14.5, -8.25, 0, 550);
        chassis.turnToPoint(0, 0, 500);
        chassis.waitUntilDone();
        target_position = 160;
    pros::delay(500);

        //Grab first mogo
    ClampUp = false;
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
        desired_ring = 2;
    pros::Task RingSort(Auton_StopIntake); 
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
        chassis.moveToPose(-49.23, 23.61, 90, 1550,{.forwards = false, .maxSpeed = 65});
        chassis.waitUntilDone();

    //90 degree with a mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0021;
    angular_controller.kD = 47;

        //Intake last ring
        chassis.turnToPoint(-49.92, 47, 300);
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000);
        chassis.moveToPose(-49.92, 39.9, 0, 700, {.minSpeed=100, .earlyExitRange=8});
        // Touch Ladder
        // chassis.turnToPoint(-48.26, 21.56, 500);
        chassis.moveToPose(-48.26, 21.56, 242, 2000,{.lead = 0, .minSpeed=100});
        chassis.waitUntil(3);
    target_position = 105;
}

void Mogo_Rush_blue(){
//Note: Middle Ring STack is 0,0
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

        chassis.setPose(11.18, -28.32, 0);
        IntakeMotor.move_voltage(-12000);

    chassis.moveToPose(5.68, 12.23, -30.79, 1000,{.lead = 0.3});
     chassis.waitUntil(3);
        IntakeMotor.brake();
        target_position = 190;
        chassis.turnToHeading(-90, 300);
        chassis.moveToPose(-7.8, 15, -90, 5000); //,{.lead = 0}
        chassis.waitUntilDone();
        //Grab mobile goal
        ClampUp = false; //Allows autoclamp to run
        chassis.moveToPose(13.78, 7.78, -45, 3000, {.forwards = false, .lead = 0}); //Fatser movement
        chassis.waitUntil(5);
        target_position = -19; //Lady brown returs to position
        chassis.moveToPose(22.37, 0, -45, 2000, {.forwards = false, .maxSpeed = 50}); //Grabs mobile goal
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000); //Scores first ring
        // IntakeMotor.move_voltage(12000);
        // chassis.turnToPoint(-0.58, float y, int timeout)
        chassis.moveToPose(-0.58, -0.28, -90, 3000); 
        chassis.waitUntil(2);
        desired_ring = 3; //Sets desired ring to blue, blue ring will stop in intake
        pros::Task RingSort(Auton_StopIntake); //function runs for sotpping intake
        ClampDown = false; //boolean to tell goal to unclamp
        ClampUp = true; //Prevents autoclalmp from clamping
        Clamp_Piston.set_value(ClampDown); //Drops  mogo

        //grab second mobile goal (rushed one) c
        // chassis.turnToPoint(-17.42, 14.51, 1000, {.forwards = false});
        chassis.moveToPose(-11.63, 12.63, -232.3, 5000, {.forwards = false,  .maxSpeed = 50}); //moves to second goal
        chassis.waitUntil(0.25); //delay to give time for goal to unclamp
        ClampUp = false; //allows autoclamp to run
        chassis.waitUntilDone();
        IntakeMotor.move_voltage(12000); //scores second ring
}

void Negative_Elim(){
//Note: Alliance Stake is 0, 0
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
        chassis.moveToPose(-14.5, -8.25, 0, 550);
        chassis.turnToPoint(0, 0, 500);
        chassis.waitUntilDone();
        target_position = 160;
    pros::delay(500);

        //Grab first mogo
    ClampUp = false;
        chassis.moveToPose(-35, -17.3, 62.2, 1100, {.forwards = false, .minSpeed=79, .earlyExitRange=8.5}); // 1400
        chassis.waitUntil(5);
    target_position = -20;
        chassis.moveToPose(-48, -24, 62.2, 500, {.forwards = false,.maxSpeed = 75}); 
        chassis.waitUntilDone();

    //115 degree with an empty mobile goal constant
    angular_controller.kP = 4.52;
    angular_controller.kI = 0.0000;
    angular_controller.kD = 47;

        //Intake first rings
    IntakeMotor.move_voltage(12000);
        chassis.turnToPoint(-58.3, -30.40, 900);
        chassis.moveToPose(-60.92, -49.6, 180, 2000, {.maxSpeed = 80}); 
        chassis.moveToPose(-60.92, -56.6, 180, 2500, {.maxSpeed = 80}); 
//Move to position for line rings
        chassis.moveToPose(-46.35, -28.4, -90, 2000, {.forwards = false, .lead = 0.1}); 
        chassis.turnToPoint(-47.1, -47.1, 800);
        chassis.moveToPose(-45.25, -40.57, 180, 1300);
        // chassis.waitUntilDone();
        // chassis.turnToPoint(-4, -4, 1000);
        // chassis.moveToPose(-4, -4, 48, 3000);
        chassis.moveToPose(-4.9, -58.56, 178.65, 2400,{.maxSpeed = 100});
        chassis.moveToPose(-15.88, -18.4, 180, 4000,{.forwards = false, .minSpeed = 80});
}