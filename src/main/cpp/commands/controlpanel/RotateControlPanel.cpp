/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/controlpanel/RotateControlPanel.h"
#include "subsystems/ControlPanelManipulator.h"

RotateControlPanel::RotateControlPanel(ControlPanelManipulator *pControlPanel, DriveTrain *pSubsystemDrive) {
  AddRequirements({pControlPanel});
  AddRequirements({pSubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
  mpSubsystemDrive = pSubsystemDrive;
}

// Called when the command is initially scheduled.
void RotateControlPanel::Initialize() {
  mpControlPanel->resetFinished();
  Lights::GetInstance()->setMode(kLights_rainbow_bounce); //for light stuffs
}

// Called repeatedly when this Command is scheduled to run
void RotateControlPanel::Execute() {
  mpControlPanel->rotationControl();
  mpSubsystemDrive->slowlyDriveForwards();
  printf("Running Rot\n");
}

// Called once the command ends or is interrupted.
void RotateControlPanel::End(bool interrupted) {
  printf("Rotation complete!\n");
  Lights::GetInstance()->setMode(kLights_enabled); //for light stuffs
  mpSubsystemDrive->stop();
}

// Returns true when the command should end.
bool RotateControlPanel::IsFinished() {
  return mpControlPanel->getFinished();
}
