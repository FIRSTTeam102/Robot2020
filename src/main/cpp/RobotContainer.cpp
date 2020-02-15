/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/XboxController.h"
#include <frc2/command/button/JoystickButton.h>
#include "commands/DriveWithXbox.h"

RobotContainer::RobotContainer(): 
  mTankDrive{}, 
  mDriverController{0},
  mDriveCommand{&mTankDrive}
{
  // Initialize all of your commands and subsystems here
  //drive
  // Configure the button bindings
  ConfigureButtonBindings();

  //mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  //mTankDrive.setDriverJoystick(&mDriverController);

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  mDriverButtonA.WhenPressed(&mRotateCommand, false);
  mDriverButtonB.WhenPressed(&mPositionCommand, true);
  mDriverButtonX.WhenHeld(&mStopPanelCommand, false);
  //mDriverButtonY.WhenHeld(&mManualPanelCommand, true);
  mDriverButtonY.WhenHeld(&mLightTestCommand, false);
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
}
