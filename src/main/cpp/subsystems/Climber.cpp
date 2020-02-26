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
    mClimbUpMotor{kClimbUpMotor},
    mClimbDownMotor{kClimbDwnMotor},
    mTopLimitSwitch{kTopClimbLimit},
    mBotLimitSwitch{kBotClimbLimit}
{

}
//stop all climber motors
void Climber::StopClimb(){
    mClimbUpMotor.Set(0);
    mClimbDownMotor.Set(0);

}

//raise the climber
void Climber::ClimberUp(){
    if (!isClimbUp()){
        mClimbUpMotor.Set(kClimberUpSpeed);
    }
    else{
        StopClimb();
    }
}
//lift the robot and bring the climber down
void Climber::ClimberDown(){
    if (!isClimbDown()){
        mClimbDownMotor.Set(kClimberDownSpeed);
        mClimbUpMotor.Set(kTakeUpPulleySlackSpeed);
    }
    else {
        StopClimb();
    }
}
// This method will be called once per scheduler run
void Climber::Periodic()  {

}