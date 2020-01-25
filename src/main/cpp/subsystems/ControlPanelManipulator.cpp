/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "subsystems/ControlPanelManipulator.h"
#include "rev/ColorSensorV3.h"


ControlPanelManipulator::ControlPanelManipulator():
    controlMotor{controlPanelMotorIndex}
	colorSensor{frc::I2C::Port::kOnboard}
{
    turnCounter = 0;
	previousColor = 0;
}

/* turns to a color specified by "targetColor" */
void ControlPanelManipulator::positionControl(char currentColor, char targetColor) { //land on color after 3 rotations
	/*
	//old code
	if(currentColor != previousColor){ //if new color reached
		turnCounter += 1; //+1 1/8th of a rotation
	}
	
	if(turnCounter >= 24 && currentColor == targetColor){ //if control panel spun 3 times and reached target color
		controlMotor.Set(0.75); //shouldn't the motor stop now?
		turnCounter = 0; //reset turnCounter
	}
	previousColor = currentColor; //prep for nex color (if they are different, sensor is now on the current color so the previous color becomes the current one for the next check)

	*/

	//new code
	if (targetColor != currentColor) { //if not on target color
		controlMotor.Set(0.75); //spin motor?
	} else {
		controlMotor.Set(0); //stop motor?
		//run "is finished"
	}
	
}

/* rotates the control panel >= 3 times */
void ControlPanelManipulator::rotationControl(char currentColor) { //rotate 3 times
	if(currentColor != previousColor){ //if new color reached
		turnCounter += 1; //+1 1/8th of a rotation
	}
	if (turnCounter < 24) {
		controlMotor.Set(0.75);
	}
	else { //turnCounter starts at 0; if rotated >= 3 times
		controlMotor.Set(0); //stop motor
		turnCounter = 0; //reset turnCounter
		//run is finished
	}
	previousColor = currentColor; //see comment on other func
}



// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {}
