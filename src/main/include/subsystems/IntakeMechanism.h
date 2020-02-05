/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <crte/Pheonix.h>

class IntakeMechanism : private frc2::SubsystemBase {
 private:
  IntakeMechanism();

  WPI_TalonSRX IntakearMotor;
  WPI_TalonSRX IntakerollerMotor;
  


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 public:

 void lowerIntakeArm();
 void  StartROllers();
 void 

  //methods, start rollers, and drop arm
  //any actions performed by your 
  
  /*
  returntype name(parameters){

  }

  void RunIntakeForwards(){
    intakerollermotor.set(1);
  }
  */

};
