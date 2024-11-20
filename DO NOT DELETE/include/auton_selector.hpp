#pragma once
#include "main.h"

class AutonSelector {
public:
    static const int NUM_AUTONS = 9; // Number of autonomous routines

    AutonSelector();                         // Constructor
    void selectAuton(int autonIndex);         // Selects an autonomous routine
    void printSelection() const;             // Prints the selected autonomous routine
    int getSelectedAuton() const;            // Returns the index of the selected auton

    bool autonArray[NUM_AUTONS];             // Array to track the selected routine
    std::string autonNames[NUM_AUTONS];      // Array of autonomous routine names
};

extern AutonSelector autonSelector;
extern void drawGUI();