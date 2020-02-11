/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/PrimeIntake.h"

PrimeIntake::PrimeIntake(Indexer* pIndexer): mpIndexer{pIndexer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pIndexer);
}

// Called when the command is initially scheduled.
void PrimeIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PrimeIntake::Execute() {
  mpIndexer->movePowerCellsToTop();
}

// Called once the command ends or is interrupted.
void PrimeIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool PrimeIntake::IsFinished() {
  return mpIndexer->isPowerCellAtTop();
}
