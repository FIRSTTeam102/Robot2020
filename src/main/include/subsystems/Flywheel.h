/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>

class Flywheel : public frc2::SubsystemBase {
 public:
  Flywheel();
  void setSpeed(int speed);
  void startMotor();
  void stopMotor();
  bool isReady();
  int getRPM();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Encoder mFlyEnc;
  WPI_TalonSRX mFlywheel;
  int targetRPS;
  int targetRP100ms;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
