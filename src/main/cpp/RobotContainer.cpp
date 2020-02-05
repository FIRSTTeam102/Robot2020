/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/Joystick.h"

RobotContainer::RobotContainer(): 
  tankDrive{}, 
  driverJoystick{0},
  driveCommand{&tankDrive}
{
  // Initialize all of your commands and subsystems here
  //drive
  // Configure the button bindings
  ConfigureButtonBindings();

  tankDrive.SetDefaultCommand(std::move(driveCommand));
  tankDrive.setDriverJoystick(&driverJoystick);


}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  driverButtonA.WhenPressed(&mRotateCommand, true);
  driverButtonB.WhenPressed(&mPositionCommand, true);
  driverButtonX.WhenHeld(&mStopPanelCommand, false);
  driverButtonY.WhenHeld(&mManualPanelCommand, true);
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;

}
