#include "main.h"
#include "auton_selector.hpp"
#include "pros/colors.h"
#include "pros/screen.h"
#include "pros/screen.hpp"


bool bluePlusSide = false;
bool blueMinusSide = false;
bool blueRush = true;
bool blueAWP = false;
bool redPlusSide = false;
bool redMinusSide = false;
bool redRush = false;
bool redAWP = false;
bool skillsAuton = false;

//Used to switch which side the auton is on to fix the asymmetrical field layout
int flip = 1;

//POOS FUNCTIONS
void drawGUI() {

    //Blue Boxes
    pros::screen::set_pen(pros::c::COLOR_BLUE);
    pros::screen::fill_rect(5,5,95,120);
    pros::screen::fill_rect(100,5,190,120);
    pros::screen::fill_rect(195,5,285,120);
    pros::screen::fill_rect(290,5,380,120);
    //Blue Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Plus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 55, "Minus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 55, "Rush");
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 55, "AWP");

    //Red Boxes
    pros::screen::set_pen(pros::c::COLOR_RED);
    pros::screen::fill_rect(5,125,95,235);
    pros::screen::fill_rect(100,125,190,235);
    pros::screen::fill_rect(195,125,285,235);
    pros::screen::fill_rect(290,125,380,235);
    //Red Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 170, "Plus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 170, "Minus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 170, "Rush");
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 170, "AWP");

    //Skills Box
    pros::screen::set_pen(pros::c::COLOR_WHITE_SMOKE);
    pros::screen::fill_rect(385,5,475,235);
    //Skills Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 406, 103, "Auton");
    pros::screen::print(pros::E_TEXT_MEDIUM, 401, 125, "Skills");

}

void touchTester() {
    int i = 0;
    pros::screen_touch_status_s_t status;
    while(1){
       status = pros::c::screen_touch_status();

       // Will print various information about the last touch
       pros::screen::print(pros::E_TEXT_MEDIUM, 1, "Touch Status (Type): %d", status.touch_status);
       pros::screen::print(pros::E_TEXT_MEDIUM, 2, "Last X: %hd", status.x);
       pros::screen::print(pros::E_TEXT_MEDIUM, 3, "Last Y: %hd", status.y);
       pros::screen::print(pros::E_TEXT_MEDIUM, 4, "Press Count: %d", status.press_count);
       pros::screen::print(pros::E_TEXT_MEDIUM, 5, "Release Count: %d", status.release_count);
       pros::delay(20);
    }
}

void autonSelector() {

pros::screen_touch_status_s_t status;
while(1){
    status = pros::c::screen_touch_status();

    //Select Blue Plus
    if (status.x >= 5 && status.y >= 5 && status.x <= 95 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(5,5,95,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Plus");

    //Adjust Bools
    bluePlusSide = true;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
    }

    //Select Blue Minus
    if (status.x >= 100 && status.y >= 5 && status.x <= 190 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(100,5,190,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 55, "Minus");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = true;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
    }

    //Select Blue Rush
    if (status.x >= 195 && status.y >= 5 && status.x <= 285 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(195,5,285,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 55, "Rush");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = true;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
    }

    //Select Blue AWP
    if (status.x >= 290 && status.y >= 5 && status.x <= 380 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(290,5,380,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 55, "AWP");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = true;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
    }

    //Select Red Plus
    if (status.x >= 5 && status.y >= 125 && status.x <= 95 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(5,125,95,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 170, "Plus");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = true;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
    }

    //Select Red Minus
    if (status.x >= 100 && status.y >= 125 && status.x <= 190 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(100,125,190,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 170, "Minus");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = true;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
    }

    //Select Red Rush
    if (status.x >= 195 && status.y >= 125 && status.x <= 285 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(195,125,285,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 170, "Rush");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = true;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
    }

    //Select Red AWP
    if (status.x >= 290 && status.y >= 125 && status.x <= 380 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(290,125,380,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 170, "AWP");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = true;
    skillsAuton = false;

    flip = 1;
    }

    //Select Auton Skills
    if (status.x >= 385 && status.y >= 5 && status.x <= 475 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_GRAY);
    pros::screen::fill_rect(385,5,475,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 406, 103, "Auton");
    pros::screen::print(pros::E_TEXT_MEDIUM, 401, 125, "Skills");

    //Adjust Bools
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = true;
    }
  }
    pros::delay(10); // Small delay to prevent overwhelming the CPU

}

void testBools() {
    // Print the current states of the boolean variables
    std::cout << "Testing Bool States:\n";
    std::cout << "Blue Plus Side: " << bluePlusSide << "\n";
    std::cout << "Blue Minus Side: " << blueMinusSide << "\n";
    std::cout << "Blue Rush: " << blueRush << "\n";
    std::cout << "Blue AWP: " << blueAWP << "\n";
    std::cout << "Red Plus Side: " << redPlusSide << "\n";
    std::cout << "Red Minus Side: " << redMinusSide << "\n";
    std::cout << "Red Rush: " << redRush << "\n";
    std::cout << "Red AWP: " << redAWP << "\n";
    std::cout << "Skills Auton: " << skillsAuton << "\n";
}

#include "main.h" 

// Define the array of boolean variables
const int NUM_VARIABLES = 10; // Adjust the size as needed
bool booleanArray[NUM_VARIABLES] = {false};

// Function to set a specific boolean to true and others to false
void setBoolean(int index) {
    if (index < 0 || index >= NUM_VARIABLES) {
        // Index out of bounds
        std::cerr << "Error: Index out of bounds" << std::endl;
        return;
    }

    // Set all elements to false
    for (int i = 0; i < NUM_VARIABLES; i++) {
        booleanArray[i] = false;
    }

    // Set the desired index to true
    booleanArray[index] = true;
}

void opcontrol() {
    // Example usage:
    setBoolean(3); // Sets the 4th boolean to true, all others to false

    // Print to verify
    for (int i = 0; i < NUM_VARIABLES; i++) {
        std::cout << "booleanArray[" << i << "] = " << booleanArray[i] << std::endl;
    }
}
