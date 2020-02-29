/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/XboxController.h"
#include <frc2/command/button/JoystickButton.h>


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
  mDriverButtonA.WhenPressed(&mFlipDriveCommand, true);//(&mPrepShootingFast, true);
  mDriverButtonB.WhenHeld(&mPositionCommand, true);//(&mPrepShootingMed, true);
  mDriverButtonX.WhenHeld(&mRotateCommand, true);//(&mStopShootingCommand, false);
  mDriverButtonY.WhenHeld(&mManualPanelCommand, false);//(&mPrepShootingSlow, true);
  mDriverButtonLB.WhenHeld(&mSlowLeftCommand, true);
  mDriverButtonRB.WhenHeld(&mSlowRightCommand, true);
  //mDriverButtonRMenu.WhenPressed(&mFlipDriveCommand, false);
  mDriverLT.WhenPressed(&mPickupCellsCommand, true);
  mDriverLT.WhenReleased(&mRaiseArmCommand, true);
  mDriverRT.WhenHeld(&mShootCommand, false);
  //mDriverUpDPad.WhenPressed(&mDeployManipulatorCommand, false);
  //mDriverDownDPad.WhenPressed(&mRetractManipulatorCommand, false);

  //mOperatorButtonA.WhenPressed(&mPrepShootingSlow, true);//(&mRotateCommand, true);
  mOperatorButtonB.WhenPressed(&mPrepShootingMed, true);//(&mPositionCommand, true);
  mOperatorButtonX.WhenHeld(&mStopShootingCommand, false);//(&mStopPanelCommand, false);
  mOperatorButtonY.WhenPressed(&mPrepShootingFast, true);//(&mManualPanelCommand, true);
  mOperatorButtonLB.WhenPressed(&mBallJamCommand, true);
  //must be added- mOperatorButtonLMenu(toggle danger buttons)
  //must be added- mOperatorButtonRMenu(switch camera command)

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
