/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LowerArm.h"

LowerArm::LowerArm() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void LowerArm::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LowerArm::Execute() {
  if (armdown != 1)
  //Arm up 90 degrees
  armdown = 0;
return
}

// Called once the command ends or is interrupted.
void LowerArm::End(bool interrupted) {}

// Returns true when the command should end.
bool LowerArm::IsFinished() { return false; }
