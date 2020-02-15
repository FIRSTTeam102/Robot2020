/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ManualControlPanel.h"

ManualControlPanel::ManualControlPanel(ControlPanelManipulator *pControlPanel, Lights* pLights) : mpLights{pLights} {
  AddRequirements({pControlPanel});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
}

// Called when the command is initially scheduled.
void ManualControlPanel::Initialize() {
  mpLights->setMode(5); //light stuffs
}

// Called repeatedly when this Command is scheduled to run
void ManualControlPanel::Execute() {
  mpControlPanel->runMotor();
}

// Called once the command ends or is interrupted.
void ManualControlPanel::End(bool interrupted) {
  mpControlPanel->stopMotor();
  mpLights->setMode(1); //light stuffs
  printf("command sent to stop lights\n\n\n\n\n");

}

// Returns true when the command should end.
bool ManualControlPanel::IsFinished() { return false; }
