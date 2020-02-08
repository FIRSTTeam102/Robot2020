/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithXbox.h"
#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Robot.h"

DriveWithXbox::DriveWithXbox(DriveTrain* pTankDrive, Lights* pLights): mpTankDrive(pTankDrive), mpLights(pLights)
 {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pTankDrive);
  AddRequirements(pLights);
}

// Called when the command is initially scheduled.
void DriveWithXbox::Initialize() {
  mpLights->setMode(1); //auto on init
}


// Called repeatedly when this Command is scheduled to run
void DriveWithXbox::Execute() {

  mpTankDrive->arcadeDrive();
  //printf("running drive!");
  mpLights->setMode(4); //enabled on drive

}

// Called once the command ends or is interrupted.
void DriveWithXbox::End(bool interrupted) {
  mpLights->setMode(0); //turn off on interrupt
}

// Returns true when the command should end.
bool DriveWithXbox::IsFinished() { return false; }
