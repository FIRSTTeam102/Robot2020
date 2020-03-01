/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/TurnDegrees.h"

TurnDegrees::TurnDegrees(DriveTrain* pDriveTrain, int degrees): mpDriveTrain{pDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  mDegrees = degrees; //Degrees positive for right, negative for left
}

// Called when the command is initially scheduled.
void TurnDegrees::Initialize() {
  startDegs = Lights::GetInstance()->getGyroAngle();
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
  readDegs = Lights::GetInstance()->getGyroAngle() - startDegs;
  if (mDegrees > 0) {
    mpDriveTrain->move(0.5, -0.5);
  }
  else {
    mpDriveTrain->move(-0.5, 0.5);
  }
  printf("Start: %d\tCurrent: %d\tOffset: %d\tTarget: %d\n",startDegs, Lights::GetInstance()->getGyroAngle(), readDegs, mDegrees);
}

// Called once the command ends or is interrupted.
void TurnDegrees::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool TurnDegrees::IsFinished() {
  if (mDegrees > 0) {
    return (readDegs >= mDegrees);
  }
  else {
    return (readDegs <= mDegrees);
  }
}
