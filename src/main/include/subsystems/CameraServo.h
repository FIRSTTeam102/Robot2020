/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include <frc/XboxController.h>
#include "Constants.h"

class CameraServo : public frc2::SubsystemBase {
 public:
  CameraServo();
    void controlServoWithJoystick();
  
    void setServoJoystick(frc::XboxController* pServoJoystick){
    mpServoJoystick = pServoJoystick;
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Servo mCameraServoX;
  frc::Servo mCameraServoY;
  frc::XboxController* mpServoJoystick;
  double horizontalPower;
  double verticalPower;
  double cameraServoXPosition;
  double cameraServoYPosition;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
