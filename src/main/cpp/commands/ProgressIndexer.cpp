/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//Autonomous stage 2
#include "commands/ProgressIndexer.h"

ProgressIndexer::ProgressIndexer(Shooter* pShooter, Indexer* pIndexer):mpShooter(pShooter), mpIndexer(pIndexer){
  AddRequirements(pShooter);
  AddRequirements(pIndexer);
  ticksPassed = 0;
  hasSeenBall = false;
}

// Called when the command is initially scheduled.
void ProgressIndexer::Initialize() {
  mpIndexer->moveUpIndexer();
}

// Called repeatedly when this Command is scheduled to run
void ProgressIndexer::Execute() {
  if(mpIndexer->isPowerCellAtTop()){
    hasSeenBall = true;
    ticksPassed = 0;
  }
  ticksPassed += 1;
}

// Called once the command ends or is interrupted.
void ProgressIndexer::End(bool interrupted) {
  mpIndexer->stopIndexer();
  mpShooter->stopMotor();
}

// Returns true when the command should end.
bool ProgressIndexer::IsFinished() { 
  if(ticksPassed >= 200 && hasSeenBall){ //Stops the command if top sensor has not seen a ball in 200 ticks (4 seconds) from the first time it saw a ball, in the assumption that all the balls have been shot. 
    return true;
  }
  return false; 
  }
