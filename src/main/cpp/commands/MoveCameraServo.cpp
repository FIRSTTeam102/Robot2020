/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MoveCameraServo.h"

MoveCameraServo::MoveCameraServo(CameraServo *m_CameraServo) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_CameraServo});
  p_CameraServo = m_CameraServo;
}

// Called when the command is initially scheduled.
void MoveCameraServo::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MoveCameraServo::Execute() {
  printf("Command called\n");
  p_CameraServo->controlServoWithJoystick();
}

// Called once the command ends or is interrupted.
void MoveCameraServo::End(bool interrupted) {}

// Returns true when the command should end.
bool MoveCameraServo::IsFinished() { return false; }
