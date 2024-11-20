#include "main.h"
#include "auton_selector.hpp"
#include "pros/colors.h"
#include "pros/screen.h"
#include "pros/screen.hpp"

AutonSelector autonSelector;

// Constructor: Initializes all booleans to false and sets default auton names
AutonSelector::AutonSelector() {
    for (int i = 0; i < NUM_AUTONS; i++) {
        autonArray[i] = false;
    }

    // Define autonomous routine names
    autonNames[0] = "SAWP_NegativeFull_Red_BarcBot";
    autonNames[1] = "Right Side";
    autonNames[2] = "Skills Challenge";
    autonNames[3] = "SAWP_NegativeFull_Red_BarcBot";
    autonNames[4] = "Right Side";
    autonNames[5] = "Skills Challenge";
    autonNames[6] = "SAWP_NegativeFull_Red_BarcBot";
    autonNames[7] = "Right Side";
    autonNames[8] = "Skills Challenge";
}

// Selects an autonomous routine by index
void AutonSelector::selectAuton(int autonIndex) {
    if (autonIndex < 0 || autonIndex >= NUM_AUTONS) {
        std::cerr << "Error: Invalid autonomous index" << std::endl;
        return;
    }

    // Set all selections to false
    for (int i = 0; i < NUM_AUTONS; i++) {
        autonArray[i] = false;
    }

    // Activate the selected autonomous routine
    autonArray[autonIndex] = true;
    std::cout << "Autonomous selected: " << autonNames[autonIndex] << std::endl;
}

// Prints the currently selected autonomous routine
void AutonSelector::printSelection() const {
    for (int i = 0; i < NUM_AUTONS; i++) {
        std::cout << autonNames[i] << ": " << (autonArray[i] ? "Selected" : "Not Selected") << std::endl;
    }
}

// Returns the index of the currently selected autonomous routine
int AutonSelector::getSelectedAuton() const {
    for (int i = 0; i < NUM_AUTONS; i++) {
        if (autonArray[i]) {
            return i;
        }
    }
    return -1; // No auton selected
}

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
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Barcbot");
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

void select() {

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
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Barcbot");

    //Adjust Bools
   autonSelector.selectAuton(0);
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

    autonSelector.selectAuton(1);

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
    autonSelector.selectAuton(2);

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
  autonSelector.selectAuton(3);

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
   autonSelector.selectAuton(4);

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
    autonSelector.selectAuton(5);

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
    autonSelector.selectAuton(6);

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
    autonSelector.selectAuton(7);

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
    autonSelector.selectAuton(8);
    }
  }
    pros::delay(10); // Small delay to prevent overwhelming the CPU

}

void testBools() {
    std::cout << "Testing Bool States:\n";

    // Call printSelection() to display all autonomi statuses
    autonSelector.printSelection();

    // Print the currently selected auton
    int selectedAuton = autonSelector.getSelectedAuton();
    if (selectedAuton != -1) {
        std::cout << "Currently Selected: " << autonSelector.autonNames[selectedAuton] << std::endl;
    } else {
        std::cout << "No autonomous routine selected!" << std::endl;
    }
}




