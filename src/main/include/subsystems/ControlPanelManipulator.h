/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"

class ControlPanelManipulator : public frc2::SubsystemBase {
 public:
  ControlPanelManipulator();
//  void turnControlPanel(char currentColor, char targetColor);
  void rotationControl(char currentColor);
  void positionControl(char currentColor, char targetColor);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  WPI_TalonSRX controlMotor;
  rev::ColorSensorV3 colorSensor;
  char previousColor;
  int turnCounter;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
