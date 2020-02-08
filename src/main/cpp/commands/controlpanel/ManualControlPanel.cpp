/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/ManualControlPanel.h"

ManualControlPanel::ManualControlPanel(ControlPanelManipulator *pControlPanel) {
  AddRequirements({pControlPanel});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
}

// Called when the command is initially scheduled.
void ManualControlPanel::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualControlPanel::Execute() {
  mpControlPanel->runMotor();
}

// Called once the command ends or is interrupted.
void ManualControlPanel::End(bool interrupted) {
  mpControlPanel->stopMotor();
}

// Returns true when the command should end.
bool ManualControlPanel::IsFinished() { return false; }
