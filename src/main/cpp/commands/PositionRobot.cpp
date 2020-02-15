/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PositionRobot.h"

PositionRobot::PositionRobot() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void PositionRobot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PositionRobot::Execute() {
  /*
  else if(ticksPassed <= (æ + ä)){         æ = ticks required to turn robot 90 degrees.
    turnRobot();                           ä = delay in ticks set by driver before autonomous
  }
  else if(ticksPassed <= (æ + ä + ø)){        ø = ticks required to move robot from whatever position it's in to infront of the power port.
    moveForward();                          Moving the robot forward will inherently stop the robot from turning...
  }
  else if(ticksPassed <= (2*æ + ø + ä)){      
    turnRobotBack();
  }
  */
}

// Called once the command ends or is interrupted.
void PositionRobot::End(bool interrupted) {
  // stopRobot();
}

// Returns true when the command should end.
bool PositionRobot::IsFinished() { 
  /*
  if(ticksPassed > (2æ + ø + ä)){
    return true;
  }
  return false; 
  }
  */
 return false;
}
