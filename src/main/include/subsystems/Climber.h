/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber(frc::XboxController* pOperatorJoystick);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void StopClimb();
  void Climb();
  
  
  void Periodic();
  
//magnetic limit switches are reversed, isClimbUp means !isClimbUp
  bool isClimbUp() { return(!mTopLimitSwitch.Get()); }
  bool isClimbDown() { return(!mBotLimitSwitch.Get()); }

  double ClimbSpeed() {
    double speed = (0 - mpOperatorJoystick->GetRawAxis(1)) / 2;
    if (-0.01 < speed && speed < 0.01){
      speed = 0;
    }
    return speed;
  }


 private:
 // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX mClimbUpMotor;
  WPI_TalonSRX mClimbDownMotor;
  frc::DigitalInput mTopLimitSwitch;
  frc::DigitalInput mBotLimitSwitch;
  frc::XboxController* mpOperatorJoystick;
  
};
