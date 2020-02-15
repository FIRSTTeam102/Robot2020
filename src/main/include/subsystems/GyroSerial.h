/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SerialPort.h>
#include "Constants.h"

class GyroSerial : public frc2::SubsystemBase {
 public:
  GyroSerial();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  int getAngle();

 private:
  frc::SerialPort mSerial;
  int angle;
  char rawData[10];
  bool negativeAngle;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
