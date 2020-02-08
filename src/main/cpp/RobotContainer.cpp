/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/Joystick.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer(): 
  tankDrive{}, 
  driverJoystick{0},
  driveCommand{&tankDrive, &mArduinoJBLights}
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
  //frc2::JoystickButton(&driverJoystick, 2)
    //.WhenPressed(TestCommand(), false);
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;
}
