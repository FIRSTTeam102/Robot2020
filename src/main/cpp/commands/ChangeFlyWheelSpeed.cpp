/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChangeFlyWheelSpeed.h"

ChangeFlyWheelSpeed::ChangeFlyWheelSpeed(Shooter* pShooter): mpShooter{pShooter} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pShooter);
}

// Called when the command is initially scheduled.
void ChangeFlyWheelSpeed::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ChangeFlyWheelSpeed::Execute() {
  if(mpXboxController->GetPOV() == 0 && mpShooter->getSpeed() < 1){
    mpShooter->setSpeed(mpShooter->getSpeed() + 0.1);
  }
  else if(mpXboxController->GetPOV() == 180 && mpShooter->getSpeed() > 0){
    mpShooter->setSpeed(mpShooter->getSpeed() - 0.1);
  }

  printf("%f", mpShooter->getSpeed());

}

// Called once the command ends or is interrupted.
void ChangeFlyWheelSpeed::End(bool interrupted) {}

// Returns true when the command should end.
bool ChangeFlyWheelSpeed::IsFinished() {
  return true;
}
