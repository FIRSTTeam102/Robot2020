/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Relay.h>
#include "subsystems/Intake.h"
#include "RobotContainer.h"
#include "Constants.h"
#include <frc/DigitalInput.h>


Intake::Intake():
    mIntakeArmMotor{kIntakeMotor,frc::Relay::kBothDirections},
    mIntakeRollerMotor{kIntakeRollerMotor, frc::Relay::kBothDirections},
    mUpSensor{kIntakeTopSensor},
    mDownSensor{kIntakeBottomSensor}
 {

}

void Intake::lowerIntakeArm() {
    mIntakeArmMotor.Set(frc::Relay::kForward);
}

void Intake::raiseIntakeArm() {
    mIntakeArmMotor.Set(frc::Relay::kReverse);
}

void Intake::stopIntakeArm(){
    mIntakeArmMotor.Set (frc::Relay::kOff);
}

void Intake::startRollers() {
    mIntakeArmMotor.Set(frc::Relay::kForward);
}

void Intake::startReverseRollers(){
    mIntakeRollerMotor.Set(frc::Relay::kReverse);
}

void Intake::stopRollers() {
    mIntakeRollerMotor.Set(frc::Relay::kOff);
}
// This method will be called once per scheduler run
void Intake::Periodic() {}
