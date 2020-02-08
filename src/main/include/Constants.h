/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

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
int constexpr k_hoodMotor = 5;
int constexpr k_flyWheelMotor = 6;

//Intake Arm & Roller Motor Controllers (SpikeRelay)
int constexpr k_IntakeMotor = 7;
double constexpr k_ArmSpeed = 0.3;
int constexpr k_IntakeRollerMotor = 8;


//Digital IO channels
//Indexer Distance Sensors (Digital Input)
 int constexpr kDIOIntake = 0;
 int constexpr kDIOBottom = 1;
 int constexpr kDIOTop = 2;

//Index Relay
 int constexpr kIndexChannel = 0;

//OI Indexes (joysticks/buttons)
int constexpr kDriverJoystick = 0;
int constexpr kOperatorJoystick = 1;

