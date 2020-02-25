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

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();
  void setSpeed(float speed);
  float getSpeed() {return (mSpeed);};
  void startMotor();
  void stopMotor();
  bool isRunning();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  WPI_TalonSRX mShooter1;
  WPI_TalonSRX mShooter2;
  float mSpeed;
  bool mIsStarted;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
