/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/Relay.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  frc::Relay climbMotor;
  frc::XboxController* mpClimberJoystick;
  void climb();
  void setClimberJoystick(frc::XboxController* pClimberJoystick){
    mpClimberJoystick = pClimberJoystick;
  };
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
