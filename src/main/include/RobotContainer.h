/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/Sendable.h>
//#include <frc/smartdashboard/SendableRegistry.h>

#include "subsystems/DriveTrain.h"
<<<<<<< HEAD
#include "subsystems/Intake.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"
#include "subsystems/ControlPanelManipulator.h"

#include "commands/DriveWithXbox.h"
#include "commands/powercell/BallJam.h"
#include "commands/powercell/PickupPowerCells.h"
#include "commands/powercell/PrepShooting.h"
#include "commands/powercell/RaiseArm.h"
#include "commands/powercell/Reset.h"
#include "commands/powercell/ShootPowerCells.h"
#include "commands/powercell/StopShootingPowerCells.h"
#include "commands/controlpanel/ManualControlPanel.h"
#include "commands/controlpanel/RotateControlPanel.h"
#include "commands/controlpanel/PositionControlPanel.h"
#include "commands/controlpanel/StopControlPanel.h"

#include "commands/NextCamera.h"
#include "commands/PreviousCamera.h"


#include "AnalogButton.h"
=======
#include "subsystems/Lights.h" //for lights
#include "subsystems/ControlPanelManipulator.h"
#include "commands/RotateControlPanel.h"
#include "commands/PositionControlPanel.h"
#include "commands/StopControlPanel.h"
#include "commands/ManualControlPanel.h"
#include "commands/LightTest.h"
#include "frc/XboxController.h"
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300

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
<<<<<<< HEAD
=======

  DriveTrain mTankDrive;
  DriveWithXbox mDriveCommand;
  Lights mLightTestSubsys; //for lights
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300
  frc::XboxController mDriverController;
  frc2::Button mDriverButtonA{[&] { return mDriverController.GetRawButton(1);}};
  frc2::Button mDriverButtonB{[&] { return mDriverController.GetRawButton(2);}};
  frc2::Button mDriverButtonX{[&] { return mDriverController.GetRawButton(3);}};
  frc2::Button mDriverButtonY{[&] { return mDriverController.GetRawButton(4);}};
  AnalogButton mDriverTriggerButtonLeft{&mDriverController,frc::XboxController::kLeftHand};
  AnalogButton mDriverTriggerButtonRight{&mDriverController,frc::XboxController::kRightHand};

  frc::XboxController mOperatorController;
  frc2::Button mOperatorButtonA{[&] { return mOperatorController.GetRawButton(1);}};
  frc2::Button mOperatorButtonB{[&] { return mOperatorController.GetRawButton(2);}};
  frc2::Button mOperatorButtonX{[&] { return mOperatorController.GetRawButton(3);}};
  frc2::Button mOperatorButtonY{[&] { return mOperatorController.GetRawButton(4);}};
  frc2::Button mOperatorButtonLB{[&] { return mOperatorController.GetRawButton(5);}};
  frc2::Button mOperatorButtonRB{[&] { return mOperatorController.GetRawButton(6);}};
  frc2::Button mOperatorBackBackwards{[&] { return mOperatorController.GetRawButton(7);}};
  frc2::Button mOperatorStartForward{[&] { return mOperatorController.GetRawButton(8);}};

  DriveTrain mTankDrive;
  DriveWithXbox mDriveCommand;

  Intake mIntake;
  Indexer mIndexer;
  Shooter mShooter;
  BallJam mBallJamCommand{&mIndexer, &mShooter};
  PickupPowerCells mPickupCellsCommand{&mIntake, &mIndexer};
  PrepShooting mPrepShootingSlow{&mIndexer, &mShooter, 250*360};
  PrepShooting mPrepShootingMed{&mIndexer, &mShooter, 500*360};
  PrepShooting mPrepShootingFast{&mIndexer, &mShooter, 1000*360};
  RaiseArm mRaiseArmCommand{&mIntake};
  Reset mResetCommand{&mIntake, &mIndexer};
  ShootPowerCells mShootCommand{&mIndexer, &mShooter};
  StopShootingPowerCells mStopShootingCommand{&mIndexer, &mShooter};

  ControlPanelManipulator mControlPanel;
  RotateControlPanel mRotateCommand{&mControlPanel, &mTankDrive};
  PositionControlPanel mPositionCommand{&mControlPanel, &mTankDrive};
  StopControlPanel mStopPanelCommand{&mControlPanel, &mTankDrive};
  ManualControlPanel mManualPanelCommand{&mControlPanel};
  LightTest mLightTestCommand{&mLightTestSubsys}; //for lights

  cs::UsbCamera mCamera1;
  cs::UsbCamera mCamera2;
  cs::UsbCamera mCamera3;
  NextCamera mNextCamCommand{&mCamera1, &mCamera2, &mCamera3};
  PreviousCamera mPrevCamCommand{&mCamera1, &mCamera2, &mCamera3};


  void ConfigureButtonBindings();

<<<<<<< HEAD
  
=======
  Lights* mpLights; //for lights
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300
};
