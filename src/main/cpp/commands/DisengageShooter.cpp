/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
    Disengage Shooter - Stop the Shooter mechanisms fly wheel
    but leave the hood in whatever position it is already in
*/
#include "commands/DisengageShooter.h"
#include "subsystems/Shooter.h"


DisengageShooter::DisengageShooter(Shooter* subsystemShooter): mpShooter{subsystemShooter} {
  // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(subsystemShooter);
}

// Called when the command is initially scheduled.
void DisengageShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DisengageShooter::Execute() {}

// Called once the command ends or is interrupted.
void DisengageShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool DisengageShooter::IsFinished() { return false; }
