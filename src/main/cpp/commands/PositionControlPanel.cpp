/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PositionControlPanel.h"

PositionControlPanel::PositionControlPanel(ControlPanelManipulator *m_ControlPanel, DriveTrain *m_SubsystemDrive) {
  AddRequirements({m_ControlPanel});
  AddRequirements({m_SubsystemDrive});
  // Use addRequirements() here to declare subsystem dependencies.
  p_ControlPanel = m_ControlPanel;
  p_SubsystemDrive = m_SubsystemDrive;
}

// Called when the command is initially scheduled.
void PositionControlPanel::Initialize() {
  p_ControlPanel->resetFinished();
}

// Called repeatedly when this Command is scheduled to run
void PositionControlPanel::Execute() {
  if(gameData.length() > 0)
  {
    switch (gameData[0])
    {
    case 'B' :
      p_ControlPanel->positionControl('R');
      break;
    case 'G' :
      p_ControlPanel->positionControl('Y');
      break;
    case 'R' :
      p_ControlPanel->positionControl('B');
      break;
    case 'Y' :
      p_ControlPanel->positionControl('G');
      break;
    default :
      printf("BAD GAME DATA\n");
      break;
    }
  }
  else {
    p_ControlPanel->positionControl('Y');
  }
  p_SubsystemDrive->slowlyDriveForwards();
  printf("Running Pos\n");
}

// Called once the command ends or is interrupted.
void PositionControlPanel::End(bool interrupted) {
  printf("Position complete!\n");
  p_SubsystemDrive->stop();
}

// Returns true when the command should end.
bool PositionControlPanel::IsFinished() {
  return p_ControlPanel->getFinished();
}
