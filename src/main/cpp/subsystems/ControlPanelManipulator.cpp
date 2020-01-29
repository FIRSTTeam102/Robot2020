/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "subsystems/ControlPanelManipulator.h"
#include <frc/smartdashboard/SmartDashboard.h>

ControlPanelManipulator::ControlPanelManipulator():
    controlMotor{controlPanelMotorIndex},
	colorSensor{frc::I2C::Port::kOnboard}
{
    turnCounter = 0;
	previousColor = 0;
	//IMPORTANT!!!!!!! ALL VALUES MUST HAVE AT LEAST SLIGHTLY DIFFERENT RED VALUES (check blue vs green)
	blue.red = 0.13;
  	blue.green = 0.43;
  	blue.blue = 0.43;
  	red.red = 0.56;
  	red.green = 0.32;
  	red.blue = 0.11;
  	yellow.red = 0.33;
  	yellow.green = 0.56;
  	yellow.blue = 0.11;
  	green.red = 0.15;
  	green.green = 0.59;
  	green.blue = 0.27;
	matching.AddColorMatch(blue);
	matching.AddColorMatch(red);
	matching.AddColorMatch(yellow);
	matching.AddColorMatch(green);
	finished = false;
}

/* turns to a color specified by "targetColor" */
void ControlPanelManipulator::positionControl(char targetColor) { //land on color after 3 rotations
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
	currentColor = getReadColor();
	if (targetColor != currentColor) { //if not on target color
		controlMotor.Set(0.75); //spin motor?
	} else {
		controlMotor.Set(0); //stop motor?
		finished = true;//run "is finished"
	}
	
}

/* rotates the control panel >= 3 times */
void ControlPanelManipulator::rotationControl() { //rotate 3 times
	currentColor = getReadColor();
	if(currentColor != previousColor){ //if new color reached
		turnCounter += 1; //+1 1/8th of a rotation
	}
	if (turnCounter < 24) {
		controlMotor.Set(0.75);
	}
	else { //turnCounter starts at 0; if rotated >= 3 times
		controlMotor.Set(0); //stop motor
		turnCounter = 0; //reset turnCounter
		finished = true;//run is finished
	}
	previousColor = currentColor; //see comment on other func
}

void ControlPanelManipulator::printColor() {
	/*frc::SmartDashboard::PutNumber("Red", matching.MatchClosestColor(colorSensor.GetColor(), confidence).red);
	frc::SmartDashboard::PutNumber("Green", matching.MatchClosestColor(colorSensor.GetColor(), confidence).green);
	frc::SmartDashboard::PutNumber("Blue", matching.MatchClosestColor(colorSensor.GetColor(), confidence).blue);
	frc::SmartDashboard::PutNumber("Confidence", confidence);
	*/frc::SmartDashboard::PutNumber("Color", getReadColor());
	printf("Printing color\n");
}

char ControlPanelManipulator::getReadColor() {
	if (matching.MatchClosestColor(colorSensor.GetColor(), confidence) == blue) {
		return 'B';
	}
	else if (matching.MatchClosestColor(colorSensor.GetColor(), confidence) == green) {
		return 'G';
	}
	else if (matching.MatchClosestColor(colorSensor.GetColor(), confidence) == red) {
		return 'R';
	}
	else if (matching.MatchClosestColor(colorSensor.GetColor(), confidence) == yellow) {
		return 'Y';
	}
	else {
		return 'X';
	}
}

bool ControlPanelManipulator::getFinished() {
	return finished;
}

// This method will be called once per scheduler run
void ControlPanelManipulator::Periodic() {}
