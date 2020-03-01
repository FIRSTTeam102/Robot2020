/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"


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

  mClimber.SetDefaultCommand(std::move(mClimbCommand));
  
  mIndexer.SetDefaultCommand(std::move(mIndexCommand));
  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  mDriverButtonA.WhenPressed(&mPrepShootingFast, true);
  mDriverButtonB.WhenPressed(&mPrepShootingMed, true);
  mDriverButtonX.WhenPressed(&mStopShootingCommand, false);
  mDriverButtonY.WhenPressed(&mPrepShootingSlow, true);
  mDriverButtonLB.WhenHeld(&mSlowLeftCommand, true);
  mDriverButtonRB.WhenHeld(&mSlowRightCommand, true);
  mDriverButtonRMenu.WhenPressed(&mFlipDriveCommand, false);
  mDriverLT.WhenPressed(&mLowerArmCommand, true);
  mDriverLT.WhenReleased(&mRaiseArmCommand, true);
  mDriverRT.WhenHeld(&mShootCommand, false);
  mDriverUpDPad.WhenPressed(&mDeployManipulatorCommand, false);
  mDriverDownDPad.WhenPressed(&mRetractManipulatorCommand, false);

  mOperatorButtonA.WhenPressed(&mRotateCommand, true);
  mOperatorButtonB.WhenPressed(&mPositionCommand, true);
  mOperatorButtonX.WhenHeld(&mStopPanelCommand, false);
  mOperatorButtonY.WhenHeld(&mManualPanelCommand, true);
  mOperatorButtonLB.WhenPressed(&mBallJamCommand, true);
  mOperatorButtonRB.WhenPressed(&mResetCommand, true);

  
   
}


frc2::Command* RobotContainer::GetAutonomousCommand(int slot, bool shoot, int move, bool shoot2) {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;
  //mAutoCommand.setAutoConfig(slot, shoot, move, shoot2);
  //return &mAutoCommand;
  return new AutonomousCode(&mTankDrive, &mIntake, &mIndexer, &mShooter, slot, shoot, move, shoot2);
}
