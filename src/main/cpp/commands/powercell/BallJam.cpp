/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/BallJam.h"

//BallJam is called in the event a Power cell ball gets jammed in the
//  shooter mechanisms fly wheel
BallJam::BallJam() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void BallJam::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void BallJam::Execute() {}

// Called once the command ends or is interrupted.
void BallJam::End(bool interrupted) {}

// Returns true when the command should end.
bool BallJam::IsFinished() { return false; }
