/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climb.h"
#include "subsystems/Climber.h"

Climb::Climb(Climber* pClimbSubsystem): mpClimberSubsystem{pClimbSubsystem}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(mpClimberSubsystem);
}

// Called when the command is initially scheduled.
void Climb::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {

  mpClimberSubsystem->Climb();
}

// Called once the command ends or is interrupted.
void Climb::End(bool interrupted) {}

// Returns true when the command should end.
bool Climb::IsFinished() { return false; }
