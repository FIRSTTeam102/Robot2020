/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeMechanism.h"
#include <ctre/phoenix.h>
#include "RobotContainer.h"
#include "Constants.h"


IntakeMechanism::IntakeMechanism():
    m_IntakeArmMotor{k_IntakeMotor},
    m_IntakeRollerMotor{k_IntakeRollerMotor},
    mArmIsDown{false}
 {
}

// This method will be called once per scheduler run
void IntakeMechanism::Periodic() {}
