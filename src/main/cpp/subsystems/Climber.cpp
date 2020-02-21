/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "RobotContainer.h"
#include "Constants.h"
Climber::Climber():
    mClimbMotor{kClimbMotor},
    mTopLimitSwitch{kTopClimbLimit},
    mBotLimitSwitch{kBotClimbLimit}
{

}

// This method will be called once per scheduler run
void Climber::Periodic() {

}
void Climber::climb() {
    double axis = mpClimberJoystick->GetRawAxis(1);
<<<<<<< HEAD
    if(axis >= 0.5) {
        climbMotor.Set(frc::Relay::kForward);
    }
    else if(axis <= -0.5) {
        climbMotor.Set(frc::Relay::kReverse);
=======
    if (axis >= 0.5 && !isClimbUp()){
        mClimbMotor.Set(frc::Relay::kForward);
    }
    if (axis <= -0.5 && !isClimbDown()){
        mClimbMotor.Set(frc::Relay::kReverse);
>>>>>>> 52a67e2e6decfec5028a484b3b5ddcbb9eb97e16
    }
    else {
        climbMotor.Set(frc::Relay::kOff);
    }
}

