/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drive/SlowTurn.h"

SlowTurn::SlowTurn(DriveTrain* pDriveTrain, bool clockwise): mpDriveTrain{pDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDriveTrain);
  mClockwise = clockwise;
}

// Called when the command is initially scheduled.
void SlowTurn::Initialize() {
  if (mClockwise) {
    mpDriveTrain->move(0.2, -0.2);
  }
  else {
    mpDriveTrain->move(-0.2, 0.2);
  }
}

// Called repeatedly when this Command is scheduled to run
void SlowTurn::Execute() {}

// Called once the command ends or is interrupted.
void SlowTurn::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool SlowTurn::IsFinished() { return false; }
