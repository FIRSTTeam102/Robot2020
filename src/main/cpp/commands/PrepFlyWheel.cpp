/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Autonomous stage 1
#include "commands/PrepFlyWheel.h"

PrepFlyWheel::PrepFlyWheel(Shooter* pShooter): mpShooter(pShooter) {
  AddRequirements(pShooter);
}

// Called when the command is initially scheduled.
void PrepFlyWheel::Initialize() {
  mpShooter->startMotor();
}

// Called repeatedly when this Command is scheduled to run
void PrepFlyWheel::Execute() {}

// Called once the command ends or is interrupted.
void PrepFlyWheel::End(bool interrupted) {
}

// Returns true when the command should end.
bool PrepFlyWheel::IsFinished() { 
  if(mpShooter->isReady()){
    return true;
  }
  return false; 
  }
