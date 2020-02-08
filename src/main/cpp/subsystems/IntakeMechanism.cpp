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
    mIntakeArmMotor{kIntakeMotor,frc::Relay::kBothDirections},
    mIntakeRollerMotor{kIntakeRollerMotor, frc::Relay::kBothDirections},
    mUpSensor{kIntakeTopSensor},
    mDownSensor{kIntakeBottomSensor}
 {

}

void IntakeMechanism::lowerIntakeArm(){
 mIntakeArmMotor.Set (frc::Relay::kOn);

}

void IntakeMechanism::raiseIntakeArm(){
 mIntakeArmMotor.Set (frc::Relay::kOn);
}

void IntakeMechanism::StartRollers(){


}
void IntakeMechanism::StopRollers(){

}

// This method will be called once per scheduler run
void IntakeMechanism::Periodic() {}
