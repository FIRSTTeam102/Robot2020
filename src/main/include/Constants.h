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

//Index Relay (SpikeRelay)
//int constexpr kIndexChannel = 2;
int constexpr kIndexChannel = 8;

//Digital IO channels
//Indexer Distance Sensors (Digital Input)
int constexpr kDIOIntake = 0;
int constexpr kDIOBottom = 1;
int constexpr kDIOTop = 2;

//Intake Limit Switches
int constexpr kIntakeTopSensor = 3;
int constexpr kIntakeBottomSensor = 4;

//OI Indexes (joysticks/buttons)
int constexpr kDriverJoystick = 0;
int constexpr kOperatorJoystick = 1;


//PWM Channels
//Servos
int constexpr kControlPanelManipServo = 0;
int constexpr kControlPanelColorServo = 1;


//Calibrated values
//Shooter Speeds
float constexpr kSlowSpeed = 0.2;
float constexpr kMedSpeed = 0.6;
float constexpr kFastSpeed = 0.85;
float constexpr kSlowAuto = 0.4;
float constexpr kFastAuto = 0.7;

//Indexer Constants
int constexpr kMaxPowerCellTravelTime = 100;

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
float constexpr kControlPanelManipServoOut = 0.0;
float constexpr kControlPanelManipServoIn = 1.0;
float constexpr kControlPanelColorServoOut = 0.0;
float constexpr kControlPanelColorServoIn = 1.0;

//Indexer bottom sensor timeout
//Spins 760 rpms (diameter 1.5"), bottom sensor ~2" in
//Band moves 60"/s
//Ball moves 19"/s
//Timeout = (gap + 7" - 2") / 19" = (gap + 5") / 19"       7" for ball, sensor is 2" in already
//Need a timeout so they are indexed far enough
double constexpr kIndexerGap = 2;
double constexpr kBottomIndexerTimeout = (kIndexerGap + 0) / 19;