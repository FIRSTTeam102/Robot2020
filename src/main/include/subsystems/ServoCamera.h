/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/Servo.h>
#include <frc2/command/SubsystemBase.h>
class ServoCamera : public frc2::SubsystemBase {
 public:
  ServoCamera();

  void setPosition(float x);
  void controlServoWithJoystick();
  void setServoJoystick(frc::Joystick* servoJoystick){
    p_servoJoystick = servoJoystick;
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Servo bottomServo;
  frc::Servo topServo;
  frc::Joystick* p_servoJoystick;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
