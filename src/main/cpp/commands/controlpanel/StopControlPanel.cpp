/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/StopControlPanel.h"

StopControlPanel::StopControlPanel(ControlPanelManipulator *pControlPanel, DriveTrain *pSubsystemDrive) {
  AddRequirements({pControlPanel});
  AddRequirements({pSubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
  mpSubsystemDrive = pSubsystemDrive;
}

// Called when the command is initially scheduled.
void StopControlPanel::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void StopControlPanel::Execute() {
  mpControlPanel->stopMotor();
  mpSubsystemDrive->stop();
}

// Called once the command ends or is interrupted.
void StopControlPanel::End(bool interrupted) {}

// Returns true when the command should end.
bool StopControlPanel::IsFinished() { return false; }
