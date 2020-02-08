/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
   Lower the Intake Mechanisms arm, so it can start collecting power cells
*/
#include "commands/powercell/LowerArm.h"
#include "subsystems/Intake.h"
#include "RobotContainer.h"
#include "Robot.h"

LowerArm::LowerArm(Intake* pIntake):
     mpIntake{pIntake}
 {
  // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(pIntake);
 }

// Called when the command is initially scheduled.
void LowerArm::Initialize() {
   mpIntake->startRollers();
   mpIntake->lowerIntakeArm();
}

// Called repeatedly when this Command is scheduled to run
void LowerArm::Execute() {
   if (mpIntake->isArmDown()){
      mpIntake->stopIntakeArm();
   }
}

// Called once the command ends or is interrupted.
void LowerArm::End(bool interrupted) {}

// Returns true when the command should end.
bool LowerArm::IsFinished() { return false; }