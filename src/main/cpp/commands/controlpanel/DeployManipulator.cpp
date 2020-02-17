/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/DeployManipulator.h"

DeployManipulator::DeployManipulator(ControlPanelManipulator* pControlPanel): mpControlPanel{pControlPanel} {
  AddRequirements(pControlPanel);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void DeployManipulator::Initialize() {
  mpControlPanel->deployManipulator();
}

// Called repeatedly when this Command is scheduled to run
void DeployManipulator::Execute() {}

// Called once the command ends or is interrupted.
void DeployManipulator::End(bool interrupted) {}

// Returns true when the command should end.
bool DeployManipulator::IsFinished() { return true; }
