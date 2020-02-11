/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/AimShooter.h"

AimShooter::AimShooter(Shooter* pShooter, int speed): mpShooter{pShooter}, mSpeed{speed} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(mpShooter);
}

// Called when the command is initially scheduled.
void AimShooter::Initialize() {
  mpShooter->setSpeed(mSpeed);
}

// Called repeatedly when this Command is scheduled to run
void AimShooter::Execute() {}

// Called once the command ends or is interrupted.
void AimShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool AimShooter::IsFinished() { return true; }
