/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanelManipulator.h"

ControlPanelManipulator::ControlPanelManipulator():
    controlMotor{4}
{
    turnCounter = 0;
}

void ControlPanelManipulator::turnControlPanel(char currentColor, char targetColor) {
	if(currentColor != previousColor){
		turnCounter += 1;
	}
	
	if(turnCounter >= 25){
		if(currentColor == targetColor){
			controlMotor.Set(0.75);
            turnCounter = 0;
		}
	}
	previousColor = currentColor;
}

// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {}
