/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/powercell/ShootPowerCells.h"
#include "subsystems/Shooter.h"
#include "subsystems/Indexer.h"

ShootPowerCells::ShootPowerCells(Shooter* pshooterSubsys, Indexer* pindexerSubsys):
  mpshooterSubsys{pshooterSubsys},
  mpindexerSubsys{pindexerSubsys} 
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pshooterSubsys);
  AddRequirements(pindexerSubsys);
}

// Called when the command is initially scheduled.
void ShootPowerCells::Initialize() {}

// Called repeatedly when this Command is scheduled to run
//  as long as the shooter is ready to take power cells, the
//  indexer should send power cells (until cancelled or empty)
void ShootPowerCells::Execute() {
   if(mpshooterSubsys->isReady()){
     mpindexerSubsys->shootPowerCell();
   }
}

// ShootPowerCells - end Called once the command ends or is interrupted.
//   stop the indexer from sending power cells to the shooter. End if the 
//   shoot command is cancelled by driver/operator or if indexer runs out
//   of power cells.
void ShootPowerCells::End(bool interrupted) {
  mpindexerSubsys->stopIndexer();
}

// shoot power cells - is finished - Returns true when the command should end.
//    if the indexer is empty, stop trying to shoot power cells.
bool ShootPowerCells::IsFinished() { 
  return (mpindexerSubsys->isEmptyIndexer()); 
}
