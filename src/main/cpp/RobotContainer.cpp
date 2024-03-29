/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <frc/shuffleboard/Shuffleboard.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/SendableCameraWrapper.h>
#include "RobotContainer.h"


RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here
  //drive
  // Configure the button bindings
  ConfigureButtonBindings();

  mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  mTankDrive.setDriverJoystick(&mDriverController);

  mCamera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  mCamera2 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
  frc::CameraServer::GetInstance()->GetServer().SetSource(mCamera1);

    frc::Shuffleboard::GetTab("Drive Info")
    .Add("Camera Stream",mCamera1)
    .WithWidget(frc::BuiltInWidgets::kCameraStream)
    .WithSize (4,3)
    .WithPosition (4,0);

  mClimber.SetDefaultCommand(std::move(mClimbCommand));
  
  mIndexer.SetDefaultCommand(std::move(mIndexCommand));
  
  mCameraServo.SetDefaultCommand(std::move(mServoCommand));
  mCameraServo.setServoJoystick(&mOperatorController);
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
  mDriverLT.WhenPressed(&mLowerArmCommand, true);
  mDriverLT.WhenReleased(&mRaiseArmCommand, true);
  mDriverRT.WhenHeld(&mShootCommand, false);
  //mDriverUpDPad.WhenPressed(&mDeployManipulatorCommand, false);
  //mDriverDownDPad.WhenPressed(&mRetractManipulatorCommand, false);

  mOperatorButtonA.WhenPressed(&mPrepShootingSlow, true);//(&mRotateCommand, true);
  mOperatorButtonB.WhenPressed(&mPrepShootingMed, true);//(&mPositionCommand, true);
  mOperatorButtonX.WhenHeld(&mStopShootingCommand, false);//(&mStopPanelCommand, false);
  mOperatorButtonY.WhenPressed(&mPrepShootingFast, true);//(&mManualPanelCommand, true);
  mOperatorButtonLB.WhenHeld(&mBallJamCommand, true);
  mOperatorButtonRB.WhenHeld(&mResetCommand, true);
  mOperatorButtonRB.WhenReleased(&mRaiseArmCommand, true);
  //must be added- mOperatorButtonLMenu(toggle danger buttons)

  //mOperatorButtonLMenu.WhenPressed(&mPrevCamCommand, true);
  mOperatorButtonRMenu.WhenPressed(&mNextCamCommand, true);

}


frc2::Command* RobotContainer::GetAutonomousCommand(int slot, bool shoot, int move, bool shoot2) {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;
  //mAutoCommand.setAutoConfig(slot, shoot, move, shoot2);
  //return &mAutoCommand;
  return new AutonomousCode(&mTankDrive, &mIntake, &mIndexer, &mShooter, slot, shoot, move, shoot2);
}
