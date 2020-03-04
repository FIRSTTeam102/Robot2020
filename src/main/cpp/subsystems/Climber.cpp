/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "RobotContainer.h"
#include "Constants.h"

Climber::Climber(frc::XboxController* pOperatorJoystick): 
    mClimbUpMotor{kClimbUpMotor},
    mClimbDownMotor{kClimbDwnMotor},
    mTopLimitSwitch{kTopClimbLimit},
    mBotLimitSwitch{kBotClimbLimit},
    mpOperatorJoystick{pOperatorJoystick}
{

}
//stop all climber motors
void Climber::StopClimb(){
    mClimbUpMotor.Set(0);
    mClimbDownMotor.Set(0);

}

//raise the climber
void Climber::Climb(){
    
    if(ClimbSpeed()>0 && !isClimbUp()){
        mClimbUpMotor.Set(ClimbSpeed());
        mClimbDownMotor.Set(0);
    }
    else if(ClimbSpeed()<0 && !isClimbDown()){
        mClimbDownMotor.Set(ClimbSpeed());
        mClimbUpMotor.Set(ClimbSpeed()*kTakeUpSlackPercent);
    }
    else{
        StopClimb();
    }
}
// This method will be called once per scheduler run
void Climber::Periodic()  {

}