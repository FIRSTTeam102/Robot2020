/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
   Lower the Intake Mechanisms arm, so it can start collecting power cells
*/
#include "commands/LowerArm.h"
#include "subsystems/IntakeMechanism.h"
#include "RobotContainer.h"
#include "Robot.h"

LowerArm::LowerArm(IntakeMechanism* subsystemIntake):
     mIntakeSubsystem{subsystemIntake}
 {
  // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(subsystemIntake);
 }

// Called when the command is initially scheduled.
void LowerArm::Initialize() {
   mIntakeSubsystem->StartRollers();
   mIntakeSubsystem->lowerIntakeArm();




}






// Called repeatedly when this Command is scheduled to run
void LowerArm::Execute() {
      if (mIntakeSubsystem->ArmisDown()){
         mIntakeSubsystem->StopIntakeArm();
      }

}

// Called once the command ends or is interrupted.
void LowerArm::End(bool interrupted) {}


// Returns true when the command should end.
bool LowerArm::IsFinished() { return false; }
