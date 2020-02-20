/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <RobotContainer.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/SendableCameraWrapper.h>
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
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
  
  mTankDrive.SetDefaultCommand(std::move(mDriveCommand));
  mTankDrive.setDriverJoystick(&mDriverController);

  mCamera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  mCamera2 = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
  mCamera3 = frc::CameraServer::GetInstance()->StartAutomaticCapture(2);
  frc::CameraServer::GetInstance()->GetServer().SetSource(mCamera1);

   //Create the default camera stream tab
  
    frc::Shuffleboard::GetTab("Auto")
    .Add("Camera Stream",mCamera1)
    .WithWidget(frc::BuiltInWidgets::kCameraStream)
    .WithSize (4,5)
    .WithPosition (2,1);

  // Configure the button bindings
  ConfigureButtonBindings();

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
  mOperatorBackBackwards.WhenPressed(&mPrevCamCommand, true);
  mOperatorStartForward.WhenPressed(&mNextCamCommand, true);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
   return NULL;
}
