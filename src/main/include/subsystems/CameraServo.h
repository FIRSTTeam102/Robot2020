/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include <frc/Joystick.h>

class CameraServo : public frc2::SubsystemBase {
 public:
  CameraServo();
    void controlServoWithJoystick();
    void setServoJoystick(frc::Joystick* servoJoystick){
    p_servoJoystick = servoJoystick;
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Servo cameraServo;
  frc::Joystick* p_servoJoystick;
  double horizontalPower;
  double cameraServoPosition;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};