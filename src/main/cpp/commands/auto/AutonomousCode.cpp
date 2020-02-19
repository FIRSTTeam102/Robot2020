/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutonomousCode.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html

AutonomousCode::AutonomousCode(DriveTrain* pDriveTrain, Intake* pIntake, Indexer* pIndexer, Shooter* pShooter, int slot, bool shoot, int move, bool shoot2){
  printf("Running auto\n");
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  if (slot == 2 || slot == 3) {
    shootSpeed = kMedAuto;
  }
  else {
    shootSpeed = kSlowAuto;
  }
  if (shoot) { //Shoot initial cells
    printf("Shooting\n");
    AddCommands(AimShooter(pShooter, shootSpeed), ShootPowerCells(pIndexer, pShooter));
  }
  if (shoot && slot == 2 && move == 1) { //Shot old balls, near trench, going to pick up trench balls
    printf("Going to trench\n");
    AddCommands(GetRascals(pDriveTrain, pIntake));
    if (shoot2) { //Shoot again
      printf("Shooting from trench\n");
      AddCommands(TurnDegrees(pDriveTrain, -11.5), AimShooter(pShooter, kFastAuto), ShootPowerCells(pIndexer, pShooter));
    }
  }
  else if (move == 2) { //Back up the whole time
    printf("Backing up\n");
    AddCommands(BackUp(pDriveTrain));
  }
  else { //Wait until very end to back up
    printf("Waiting\n");
    if (frc::DriverStation::GetInstance().GetMatchTime() < 1.5) {
      printf("Backing up\n");
      AddCommands(BackUp(pDriveTrain));
    }
  }
}
