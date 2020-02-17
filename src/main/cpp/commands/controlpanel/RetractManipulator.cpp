/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/RetractManipulator.h"

RetractManipulator::RetractManipulator(ControlPanelManipulator* pControlPanel): mpControlPanel{pControlPanel} {
  AddRequirements(pControlPanel);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void RetractManipulator::Initialize() {
  mpControlPanel->retractManipulator();
}

// Called repeatedly when this Command is scheduled to run
void RetractManipulator::Execute() {}

// Called once the command ends or is interrupted.
void RetractManipulator::End(bool interrupted) {}

// Returns true when the command should end.
bool RetractManipulator::IsFinished() { return true; }
