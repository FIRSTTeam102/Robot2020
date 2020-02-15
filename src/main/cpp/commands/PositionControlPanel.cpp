/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PositionControlPanel.h"

PositionControlPanel::PositionControlPanel(ControlPanelManipulator *pControlPanel, DriveTrain *pSubsystemDrive, Lights *pLights) : mpLights{pLights} {
  AddRequirements({pControlPanel});
  AddRequirements({pSubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  mpControlPanel = pControlPanel;
  mpSubsystemDrive = pSubsystemDrive;
}

// Called when the command is initially scheduled.
void PositionControlPanel::Initialize() {
  mpLights->setMode(8); //for light stuffs
  mpControlPanel->resetFinished();
}

// Called repeatedly when this Command is scheduled to run
void PositionControlPanel::Execute() {
  /*
  if(gameData.length() > 0)
  {
    switch (gameData[0])
    {
    case 'B' :
      mpControlPanel->positionControl('R');
      break;
    case 'G' :
      mpControlPanel->positionControl('Y');
      break;
    case 'R' :
      mpControlPanel->positionControl('B');
      break;
    case 'Y' :
      mpControlPanel->positionControl('G');
      break;
    default :
      printf("BAD GAME DATA\n");
      break;
    }
  }
  else {
    mpControlPanel->positionControl('Y');
  }
  mpSubsystemDrive->slowlyDriveForwards();
  printf("Running Pos\n");
  */
}

// Called once the command ends or is interrupted.
void PositionControlPanel::End(bool interrupted) {
  printf("Position complete!\n");
  mpLights->setMode(0); //for light stuffs
  mpSubsystemDrive->stop();
}

// Returns true when the command should end.
bool PositionControlPanel::IsFinished() {
  return mpControlPanel->getFinished();
}
