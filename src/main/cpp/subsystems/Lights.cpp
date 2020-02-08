/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lights.h"


Lights::Lights() : mSP{9600, frc::SerialPort::kOnboard} {

}

// This method will be called once per scheduler run
void Lights::Periodic() {
    mSP.Write("1", 1);
}
