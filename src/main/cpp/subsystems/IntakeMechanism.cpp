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
#include <frc/DigitalInput.h>


IntakeMechanism::IntakeMechanism():
    mIntakeArmMotor{kIntakeMotor,frc::Relay::kBothDirections},
    mIntakeRollerMotor{kIntakeRollerMotor, frc::Relay::kBothDirections},
    mUpSensor{kIntakeTopSensor},
    mDownSensor{kIntakeBottomSensor}
 {

}

void IntakeMechanism::lowerIntakeArm(){
 mIntakeArmMotor.Set (frc::Relay::kForward);
    
}

void IntakeMechanism::raiseIntakeArm(){
 mIntakeArmMotor.Set (frc::Relay::kReverse);
}

void IntakeMechanism::StartRollers(){
    mIntakeArmMotor.Set (frc::Relay::kForward);


}
void IntakeMechanism::StopRollers(){
    mIntakeRollerMotor.Set (frc::Relay::kOff);
}
void IntakeMechanism::StartReverseRollers(){
    mIntakeRollerMotor.Set (frc::Relay::kReverse);

}
void IntakeMechanism::StopIntakeArm(){
    mIntakeArmMotor.Set (frc::Relay::kOff);
}
// This method will be called once per scheduler run
void IntakeMechanism::Periodic() {}
