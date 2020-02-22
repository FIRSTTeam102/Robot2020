/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drive/FlipDrive.h"

FlipDrive::FlipDrive(DriveTrain* pDriveTrain): mpDriveTrain{pDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void FlipDrive::Initialize() {
  mpDriveTrain->flipDrive();
}

// Called repeatedly when this Command is scheduled to run
void FlipDrive::Execute() {}

// Called once the command ends or is interrupted.
void FlipDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool FlipDrive::IsFinished() { return true; }
