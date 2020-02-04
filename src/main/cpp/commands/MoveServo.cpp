/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MoveServo.h"
#include "subsystems/ServoCamera.h"
MoveServo::MoveServo() {

  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void MoveServo::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void MoveServo::Execute() {}

// Called once the command ends or is interrupted.
void MoveServo::End(bool interrupted) {}

// Returns true when the command should end.
bool MoveServo::IsFinished() { return false; }
