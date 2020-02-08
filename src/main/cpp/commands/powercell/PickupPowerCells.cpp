/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
    PickupPowerCells - if the intake arm is not lowered, lower it & start the
      intake arm motors. If a ball is detected by the indexer, the indexer
      should take the ball in.
*/
#include "commands/powercell/PickupPowerCells.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
PickupPowerCells::PickupPowerCells() {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
