/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/* Listing of names:
 *  
 * #  <list>  --> <used for...>, <color desc.>
 * 1  blues   --> Auto, blue
 * 2  yellows --> Shooting, yellow
 * 3  reds    --> Disabled, orange (used to be red)
 * 4  oranges --> Default, orange
 * 5  greens  --> Ready to shoot, green (may have been reassigned to shooting)
 * 6  colors  --> Climbing, rainbow
 * 7  fire    --> Fire
 * 8  rygb    --> Rotation/Position control, rainbow
 */

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
