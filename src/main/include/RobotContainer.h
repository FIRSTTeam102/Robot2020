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
#include "subsystems/SerialNano.h"
#include "subsystems/SerialUno.h"
#include "commands/RotateControlPanel.h"
#include "commands/PositionControlPanel.h"
#include "commands/StopControlPanel.h"
#include "commands/ManualControlPanel.h"
#include "frc/XboxController.h"
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

  frc::XboxController* GetDriverJoystick(){
    return &mDriverController;
  }
  

 private:
 
  // The robot's subsystems and commands are defined here...
  DriveTrain mTankDrive;
  DriveWithXbox mDriveCommand;
  frc::XboxController mDriverController;
  frc2::Button mDriverButtonA{[&] { return mDriverController.GetRawButton(1);}};
  frc2::Button mDriverButtonB{[&] { return mDriverController.GetRawButton(2);}};
  frc2::Button mDriverButtonX{[&] { return mDriverController.GetRawButton(3);}};
  frc2::Button mDriverButtonY{[&] { return mDriverController.GetRawButton(4);}};
  
  ControlPanelManipulator mControlPanel;
  RotateControlPanel mRotateCommand{&mControlPanel, &mTankDrive};
  PositionControlPanel mPositionCommand{&mControlPanel, &mTankDrive};
  StopControlPanel mStopPanelCommand{&mControlPanel, &mTankDrive};
  ManualControlPanel mManualPanelCommand{&mControlPanel};

  SerialNano mSerialNano;
  SerialUno mSerialUno;

  void ConfigureButtonBindings();
};
