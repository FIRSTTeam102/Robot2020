/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/Reset.h"

Reset::Reset(Intake* pIntake, Indexer* pIndexer): mpIntake{pIntake}, mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pIntake);
  AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void Reset::Initialize() {
  mpIndexer->movePowerCellsToBottom();
}

// Called repeatedly when this Command is scheduled to run
void Reset::Execute() {
  mpIntake->lowerIntakeArm();
  mpIntake->startReverseRollers();
}

// Called once the command ends or is interrupted.
void Reset::End(bool interrupted) {
  mpIntake->stopRollers();
}

// Returns true when the command should end.
bool Reset::IsFinished() {
    if (mpIndexer->isRunningOnEmpty())){
        return true;
    } else{
        return false;
    }

}
