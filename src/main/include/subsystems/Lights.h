/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SerialPort.h>

#define _GLIBCXX_USE_CXX11_ABI 1



class Lights : public frc2::SubsystemBase {
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
private:
  Lights();
  static Lights *mpLightsInstance;
public: 
  static Lights* GetInstance();   
  void Periodic();
  void setMode(int mode);
  //int getGyroAngle();

 private:
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::SerialPort mSP;
  char strMode[1];
  char readBuffer[25];
};

//Lights::GetInstance()->setMode(int Mode);