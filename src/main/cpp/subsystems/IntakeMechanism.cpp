/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>
#include "subsystems/IntakeMechanism.h"
#include "RobotContainer.h"
#include "Constants.h"


IntakeMechanism::IntakeMechanism():
    m_IntakeArmMotor{k_IntakeMotor, Direction::kBothDirections},
    m_IntakeRollerMotor{k_IntakeRollerMotor, Directions:: kBothDirections}
 {

}

void IntakeMechanism::lowerIntakeArm(){
 motor.Set (-k_ArmSpeed);

}

void IntakeMechanism::raiseIntakeArm(){
 motor.Set (k_ArmSpeed);
}

void IntakeMechanism::StartROllers(){

}


// This method will be called once per scheduler run
void IntakeMechanism::Periodic() {}
