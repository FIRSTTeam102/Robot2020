/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <frc/Encoder.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// Talon SRX motor controllers
// Drive motor controllers
int constexpr kTopLeftMotor = 0;
int constexpr kTopRightMotor = 1;
int constexpr kBottomLeftMotor = 2;
int constexpr kBottomRightMotor = 3;

// Control panel motor controller (TalonSRx)
int constexpr kControlPanelMotor = 4;

//Shooter Motor Controllers (TalonSRX)
int constexpr kFlyMotor = 5;

//Climb Motor Controllers (TalonSRX)
// up raises the climb system, down retracts it & lifts the robot
int constexpr kClimbUpMotor = 6;
int constexpr kClimbDwnMotor = 9;
double constexpr kClimberUpSpeed = 0.5;
double constexpr kClimberDownSpeed = 0.1;
double constexpr kTakeUpPulleySlackSpeed = 0.01;

//Intake Arm & Roller Motor Controllers (SpikeRelay)
int constexpr kIntakeMotor = 7;
int constexpr kIntakeRollerMotor = 8;



//Digital IO channels
//Indexer Distance Sensors (Digital Input)
 int constexpr kDIOIntake = 0;
 int constexpr kDIOBottom = 1;
 int constexpr kDIOTop = 2;

//Index Relay
 int constexpr kIndexChannel = 0;
 int constexpr kMaxPowerCellTravelTime = 100;

//OI Indexes (joysticks/buttons)
int constexpr kDriverJoystick = 0;
int constexpr kOperatorJoystick = 1;

//Limit Switches
int constexpr kTopClimbLimit = 0;
int constexpr kBotClimbLimit = 1;
int constexpr kIntakeTopSensor = 2;
int constexpr kIntakeBottomSensor = 3;

//Flywheel encoder indexes
int constexpr kFlyEncA = 0;
int constexpr kFlyEncB = 1;
bool constexpr kReverseFlyEnc = false;
frc::Encoder::EncodingType constexpr kFlyEncType = frc::Encoder::EncodingType::k4X;