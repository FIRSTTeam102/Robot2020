/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LightTest.h"


LightTest::LightTest(Lights* pLights) : mpLights{pLights} {}

// Called when the command is initially scheduled.
void LightTest::Initialize() {
  mpLights->setMode(3); //loop pattern on init
}

// Called once the command ends or is interrupted.
void LightTest::End(bool interrupted) {
  //mpLights->setMode(2); //turn off on interrupt
}

void LightTest::Execute() {
  //mpLights->setMode(5); //loop pattern on execute
}

// Returns true when the command should end.
bool LightTest::IsFinished() { return false; }
