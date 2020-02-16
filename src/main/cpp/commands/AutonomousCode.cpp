/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutonomousCode.h"
#include "commands/powercell/AimShooter.h"
#include "commands/powercell/ShootPowerCells.h"
#include "commands/BackUp.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html

AutonomousCode::AutonomousCode(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer, Shooter* pShooter, GyroSerial* pSerial, int slot, bool shoot, int move, bool shoot2){
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  if (shoot) {
    AddCommands(AimShooter(pShooter, shootSpeed), ShootPowerCells(pIndexer, pShooter));
  }
  if (slot == 3 && move == 1) {
    AddCommands(GetRascals(pDriveTrain, pIntake, pSerial));
    if (shoot2) {
      AddCommands(AimShooter(pShooter, kFastAuto), ShootPowerCells(pIndexer, pShooter));
    }
  }
  else if (move == 2) {
    AddCommands(BackUp(pDriveTrain));
  }
}
