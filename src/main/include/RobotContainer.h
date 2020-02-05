/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/DriveWithXbox.h"
#include "commands/ReadyShooter.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/Shooter.h"
#include "frc/Joystick.h"



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

  void ConfigureButtonBindings();


  //frc::Joystick LeftStick{1};
  //frc::XBoxController IndexerController{2}
  //frc2::JoystickButton RightTriggerButton(&exampleStick, 1);
  frc2::Trigger mRightTrigger{[&] { return driverJoystick.GetRawAxis(3);}};

  Shooter mShooter;
  ReadyShooter mReadyShooterCommand{&mShooter};
};
