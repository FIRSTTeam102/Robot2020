/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/Relay.h>
#include "Constants.h"

class IntakeMechanism : public frc2::SubsystemBase {
 public:
  IntakeMechanism();
  


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();


 void lowerIntakeArm();
 void raiseIntakeArm();
 void StartROllers();
 
 private:
  
  frc::Relay m_IntakeArmMotor;
  frc::Relay m_IntakeRollerMotor;

 

};
