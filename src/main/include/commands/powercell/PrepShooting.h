/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include "commands/powercell/AimShooter.h"
#include "commands/powercell/PrimeIntake.h"
#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"

class PrepShooting
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 PrepShooting> {
 public:
  PrepShooting(Indexer* pIndexer, Shooter* pShooter, int shooterSpeed);
};
