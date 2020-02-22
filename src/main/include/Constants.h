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

// Talon SRX motor controllers (CAN Bus)
// Drive motor controllers
int constexpr kTopLeftMotor = 0;
int constexpr kTopRightMotor = 2;
int constexpr kBottomLeftMotor = 1;
int constexpr kBottomRightMotor = 3;

// Control panel motor controller (TalonSRX)
int constexpr kControlPanelMotor = 4;

//Shooter Motor Controllers (TalonSRX)
int constexpr kFlyMotor1 = 5;
int constexpr kFlyMotor2 = 6;

//Intake Arm & Roller Motor Controllers (SpikeRelay)
int constexpr kIntakeMotor = 0;
int constexpr kIntakeRollerMotor = 1;
int constexpr kIntakeTopSensor = 2;
int constexpr kIntakeBottomSensor = 3;


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


//PWM Channels
//Servos
int constexpr kControlPanelServo = 4;


//Calibrated values
//Shooter Speeds
float constexpr kSlowSpeed = 0.4;
float constexpr kMedSpeed = 0.6;
float constexpr kFastSpeed = 0.85;
float constexpr kSlowAuto = 0.4;
float constexpr kFastAuto = 0.7;

//Color values
float constexpr kBlueR = 0.13;
float constexpr kBlueG = 0.43;
float constexpr kBlueB = 0.43;
float constexpr kRedR = 0.56;
float constexpr kRedG = 0.32;
float constexpr kRedB = 0.11;
float constexpr kYelR = 0.33;
float constexpr kYelG = 0.56;
float constexpr kYelB = 0.11;
float constexpr kGrnR = 0.14;
float constexpr kGrnG = 0.60;
float constexpr kGrnB = 0.26;

//Servo positions
float constexpr kControlPanelServoOut = 0.15;
float constexpr kControlPanelServoIn = 0.7;