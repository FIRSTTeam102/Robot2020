/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ReadyShooter.h"
#include "subsystems/Shooter.h"

ReadyShooter::ReadyShooter(Shooter* subsystemShooter) {
  AddRequirements({subsystemShooter});
  // Use addRequirements() here to declare subsystem dependencies.
  mpShooter = subsystemShooter;
}

// Called when the command is initially scheduled.
void ReadyShooter::Initialize() {}

  int SensorDetectsBall;
  int SensorNoball;

  SensorDetectsBall = 1;
  SensorNoball = 0;
}



// Called repeatedly when this Command is scheduled to run
void ReadyShooter::Execute() {
  if ()
}

// Called once the command ends or is interrupted.
void ReadyShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool ReadyShooter::IsFinished() { return false; }
