/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotateControlPanel.h"
#include "subsystems/ControlPanelManipulator.h"

RotateControlPanel::RotateControlPanel(ControlPanelManipulator *m_ControlPanel) {
  AddRequirements({m_ControlPanel});
  // Use addRequirements() here to declare subsystem dependencies.
  p_ControlPanel = m_ControlPanel;
}

// Called when the command is initially scheduled.
void RotateControlPanel::Initialize() {
  p_ControlPanel->resetFinished();
}

// Called repeatedly when this Command is scheduled to run
void RotateControlPanel::Execute() {
  p_ControlPanel->rotationControl();
  printf("Running Rot\n");
}

// Called once the command ends or is interrupted.
void RotateControlPanel::End(bool interrupted) {
  printf("Rotation complete!\n");
}

// Returns true when the command should end.
bool RotateControlPanel::IsFinished() {
  return p_ControlPanel->getFinished();
}
