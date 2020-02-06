/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include "RobotContainer.h"
#include "Constants.h"


Shooter::Shooter():
   m_Hood{k_hoodMotor},
   m_Flywheel{k_flyWheelMotor}
{
}

// This method will be called once per scheduler run
void Shooter::Periodic() {

}
