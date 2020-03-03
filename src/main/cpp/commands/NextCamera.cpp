/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/shuffleboard/ShuffleBoard.h>
#include "commands/NextCamera.h"

NextCamera::NextCamera(cs::UsbCamera* Camera1, cs::UsbCamera* Camera2, cs::UsbCamera* Camera3) 
   : mCamera1{Camera1},
    mCamera2{Camera2},
    mCamera3{Camera3},
    mCameraSource{1}
{
  // Use addRequirements() here to declare subsystem dependencies.
}
// Called when the command is initially scheduled.
void NextCamera::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void NextCamera::Execute() {
  if (mCameraSource == 1) {
    frc::CameraServer::GetInstance()->GetServer().SetSource(*mCamera2);
    frc::Shuffleboard::GetTab("Auto")
    .Add("Current Camera", mCamera2);
    mCameraSource = 2;
   }
   else if (mCameraSource == 2) {
    frc::CameraServer::GetInstance()->GetServer().SetSource(*mCamera3);
     mCameraSource = 3;
   }
   else {
    frc::CameraServer::GetInstance()->GetServer().SetSource(*mCamera1);
     mCameraSource = 1;
   }
}

// Called once the command ends or is interrupted.
void NextCamera::End(bool interrupted) {}

// Returns true when the command should end.
bool NextCamera::IsFinished() { return true; }