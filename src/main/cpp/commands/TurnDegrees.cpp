/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnDegrees.h"

TurnDegrees::TurnDegrees(DriveTrain* pDriveTrain, GyroSerial* pSerial, int degrees): mpDriveTrain{pDriveTrain}, mpSerial{pSerial} {
  // Use addRequirements() here to declare subsystem dependencies.
  mDegrees = degrees; //Degrees positive for right, negative for left
}

// Called when the command is initially scheduled.
void TurnDegrees::Initialize() {
  if (mDegrees > 0) {
    mpDriveTrain->move(0.5, -0.5);
  }
  else {
    mpDriveTrain->move(-0.5, 0.5);
  }
}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute() {
  readDegs = mpSerial->getAngle();
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
