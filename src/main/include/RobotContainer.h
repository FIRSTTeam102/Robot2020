/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/DriveWithXbox.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/ControlPanelManipulator.h"
#include "commands/RotateControlPanel.h"
#include "commands/PositionControlPanel.h"
#include "frc/Joystick.h"
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  frc::Joystick* GetDriverJoystick(){
    return &driverJoystick;
  }
  

 private:
 
  // The robot's subsystems and commands are defined here...
  DriveTrain tankDrive;
  DriveWithXbox driveCommand;
  frc::Joystick driverJoystick;
  frc2::Button driverButtonA{[&] { return driverJoystick.GetRawButton(1);}}; 
  frc2::Button driverButtonB{[&] { return driverJoystick.GetRawButton(2);}};  
  
  ControlPanelManipulator m_ControlPanel;
  RotateControlPanel m_RotateCommand{&m_ControlPanel};
  PositionControlPanel m_PositionCommand{&m_ControlPanel};

  void ConfigureButtonBindings();
};
