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
void Climber::climb(){
    double axis = mpClimberJoystick->GetRawAxis(1);
    if (axis >= 0.5 && !isClimbUp()){
        mClimbMotor.Set(frc::Relay::kForward);
    }
    if (axis <= -0.5 && !isClimbDown()){
        mClimbMotor.Set(frc::Relay::kReverse);
    }
}

