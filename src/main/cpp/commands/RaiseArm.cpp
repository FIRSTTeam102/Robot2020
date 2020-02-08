/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
   Stop the intake mechanisms rollers and raise the arm
*/
#include "commands/RaiseArm.h"

RaiseArm::RaiseArm(IntakeMechanism* psubsysIntake): mpsubsysIntake{psubsysIntake} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(psubsysIntake);
}

// Called when the command is initially scheduled.
void RaiseArm::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RaiseArm::Execute() {

}

// Called once the command ends or is interrupted.
void RaiseArm::End(bool interrupted) {}

// Returns true when the command should end.
bool RaiseArm::IsFinished() { return false; }
