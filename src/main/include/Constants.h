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
//Drive Motor Controllers (TalonSRX)
int constexpr k_topLeftMotor = 0;
int constexpr k_topRightMotor = 1;
int constexpr k_bottomLeftMotor = 2;
int constexpr k_bottomRightMotor = 3;

//Control Panel Motor Controller (TalonSRX)
int constexpr k_controlPanelMotor = 4;

//Shooter Motor Controllers (TalonSRX)
int constexpr k_hoodMotor = 5;
int constexpr k_flyWheelMotor = 6;

//Intake Arm & Roller Motor Controllers (SpikeRelay)
int constexpr k_IntakeMotor = 7;
double constexpr k_ArmSpeed = 0.3;
int constexpr k_IntakeRollerMotor = 8;


//OI Indexes (joysticks/buttons)
int constexpr k_driverJoystick = 0;
int constexpr k_operatorJoystick = 1;

//Digital IO channels
//Indexer Distance Sensors (Digital Input)
 int constexpr kDIOIntake = 0;
 int constexpr kDIOBottom = 1;
 int constexpr kDIOTop = 2;

//Index Relay
 int constexpr kIndexChannel = 0;

