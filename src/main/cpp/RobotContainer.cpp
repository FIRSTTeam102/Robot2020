/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/XboxController.h"
#include <frc2/command/button/JoystickButton.h>
#include "AnalogButton.h"


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

  mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  mTankDrive.setDriverJoystick(&mDriverController);
  
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  mDriverButtonA.WhenPressed(&mRotateCommand, true);
  mDriverButtonB.WhenPressed(&mPositionCommand, true);
  mDriverButtonX.WhenHeld(&mStopPanelCommand, false);
  mDriverButtonY.WhenHeld(&mManualPanelCommand, true);
  mDriverTriggerButtonLeft.WhenPressed(&mPickupCellsCommand, true);
  mDriverTriggerButtonLeft.WhenReleased(&mRaiseArmCommand, true);
  mDriverTriggerButtonRight.WhenHeld(&mShootCommand, false);

  mOperatorButtonA.WhenPressed(&mPrepShootingFast, false);
  mOperatorButtonB.WhenPressed(&mPrepShootingMed, false);
  mOperatorButtonX.WhenPressed(&mStopShootingCommand, false);
  mOperatorButtonY.WhenPressed(&mPrepShootingSlow, false);
  mOperatorButtonLB.WhenPressed(&mBallJamCommand, true);
  mOperatorButtonRB.WhenPressed(&mResetCommand, true);

  //Create a triggers to activate deactivate the Intake of Power cells
  // when the driver's trigger is pulled - note these are two different
  // uses of the word trigger. frc trigger is any event or set of events that
  // are true and should cause a command to be executed (like the XboxTrigger being 
  // pressed)
  
   
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;

}
