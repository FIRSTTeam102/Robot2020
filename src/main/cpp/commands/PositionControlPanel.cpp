/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PositionControlPanel.h"

PositionControlPanel::PositionControlPanel(ControlPanelManipulator *m_ControlPanel) {
  AddRequirements({m_ControlPanel});
  // Use addRequirements() here to declare subsystem dependencies.
  p_ControlPanel = m_ControlPanel;
}

// Called when the command is initially scheduled.
void PositionControlPanel::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PositionControlPanel::Execute() {
  p_ControlPanel->positionControl();
  printf("Running Pos\n");}

// Called once the command ends or is interrupted.
void PositionControlPanel::End(bool interrupted) {
  printf("Position complete!\n");
}

// Returns true when the command should end.
bool PositionControlPanel::IsFinished() {
  return p_ControlPanel->getFinished();
}
