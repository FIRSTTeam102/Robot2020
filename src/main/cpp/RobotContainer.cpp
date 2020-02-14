/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <RobotContainer.h>
#include "frc/XboxController.h"
<<<<<<< HEAD
#include "frc2/command/button/JoystickButton.h"
#include "AnalogButton.h"
=======
#include <frc2/command/button/JoystickButton.h>
#include "commands/DriveWithXbox.h"
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300

RobotContainer::RobotContainer(): 
  mTankDrive{}, 
  mDriverController{0},
  mOperatorController{1},
  mDriveCommand{&mTankDrive},
  mIntake{}
  {
  // Initialize all of your commands and subsystems here
  //drive
  // Configure the button bindings
  ConfigureButtonBindings();

<<<<<<< HEAD
  mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  mTankDrive.setDriverJoystick(&mDriverController);
  
=======
  //mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  //mTankDrive.setDriverJoystick(&mDriverController);

>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  mDriverButtonA.WhenPressed(&mRotateCommand, false);
  mDriverButtonB.WhenPressed(&mPositionCommand, true);
  mDriverButtonX.WhenHeld(&mStopPanelCommand, false);
  mDriverButtonY.WhenHeld(&mManualPanelCommand, true);
<<<<<<< HEAD
  mDriverTriggerButtonLeft.WhenPressed(&mPickupCellsCommand, true);
  mDriverTriggerButtonLeft.WhenReleased(&mRaiseArmCommand, true);
  mDriverTriggerButtonRight.WhenHeld(&mShootCommand, false);

  mOperatorButtonA.WhenPressed(&mPrepShootingFast, false);
  mOperatorButtonB.WhenPressed(&mPrepShootingMed, false);
  mOperatorButtonX.WhenPressed(&mStopShootingCommand, false);
  mOperatorButtonY.WhenPressed(&mPrepShootingSlow, false);
  mOperatorButtonLB.WhenPressed(&mBallJamCommand, true);
  mOperatorButtonRB.WhenPressed(&mResetCommand, true);
=======
  //mDriverButtonY.WhenHeld(&mLightTestCommand, false);
}
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300

  //Create a triggers to activate deactivate the Intake of Power cells
  // when the driver's trigger is pulled - note these are two different
  // uses of the word trigger. frc trigger is any event or set of events that
  // are true and should cause a command to be executed (like the XboxTrigger being 
  // pressed)

//Actual Code:
frc::SmartDashboard::PutNumber("Cow", 7);

//Test Code (Use/Select tab)
ShuffleboardTab& tab = Shuffleboard::GetTab("replace");
Shuffleboard::SelectTab("replace")

//Test Code (Sending data)

Shuffleboard::GetTab("Numbers")

//frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
<<<<<<< HEAD
 // return &m_autonomousCommand;
=======
  //return &m_autonomousCommand;
>>>>>>> 1f83a5de1c7e7df1076b0af91ee5dd23224b5300
}
