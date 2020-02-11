/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lights.h"
//#define _GLIBCXX_USE_CXX11_ABI 0


Lights::Lights() : mSP{9600, frc::SerialPort::kUSB} {
    mSP.DisableTermination();
    mSP.Reset();
}

// This method will be called once per scheduler run
void Lights::Periodic() {
    //mSP.Write("1", 1);
}

void Lights::setMode(int mode) {
    //mSP.Write((char*)mode, 1);

    if (mode >= 0 || mode <= 8) {
        strMode[0] = mode + '0';
        mSP.Write(strMode, 128);
        printf("Writing serial- mode %c\n", strMode[0]);
    } else {
        mSP.Write("0", 8);
        printf("Serial input unknown\n");
    }

}
