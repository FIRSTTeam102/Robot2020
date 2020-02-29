/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"
#include <frc/XboxController.h>
/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ChangeFlyWheelSpeed
    : public frc2::CommandHelper<frc2::CommandBase, ChangeFlyWheelSpeed> {
 public:
  ChangeFlyWheelSpeed(Shooter* pShooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  void setXboxController(frc::XboxController* pXboxController){
    mpXboxController = pXboxController;
  };

  bool IsFinished() override;
  private:
   frc::XboxController* mpXboxController;
   Shooter* mpShooter;
   bool halt = true;
};
