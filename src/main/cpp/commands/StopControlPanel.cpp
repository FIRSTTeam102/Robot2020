/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopControlPanel.h"

StopControlPanel::StopControlPanel(ControlPanelManipulator *m_ControlPanel, DriveTrain *m_SubsystemDrive) {
  AddRequirements({m_ControlPanel});
  AddRequirements({m_SubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  p_ControlPanel = m_ControlPanel;
  p_SubsystemDrive = m_SubsystemDrive;
}

// Called when the command is initially scheduled.
void StopControlPanel::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopControlPanel::Execute() {
  p_ControlPanel->stopMotor();
  p_SubsystemDrive->stop();
}

// Called once the command ends or is interrupted.
void StopControlPanel::End(bool interrupted) {}

// Returns true when the command should end.
bool StopControlPanel::IsFinished() { return false; }
