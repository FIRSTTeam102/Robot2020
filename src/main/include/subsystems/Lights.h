/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SerialPort.h>
#define _GLIBCXX_USE_CXX11_ABI 0



class Lights : public frc2::SubsystemBase {
 public:
  Lights();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void setMode(int mode);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // cool it's a serial port
  // write some stuff

  // great we're done

  frc::SerialPort mSP;
  char strMode[1];
};
