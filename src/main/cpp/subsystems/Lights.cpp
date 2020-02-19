/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/Lights.h>
//#define _GLIBCXX_USE_CXX11_ABI 0

Lights* Lights::mpLightsInstance=NULL;

Lights::Lights() : mSP{115200, frc::SerialPort::kUSB} {
    mSP.EnableTermination();
    mSP.Reset();
}

// (String)Spell
// don't mind me, just casting a spell

// This method will be called once per scheduler run
void Lights::Periodic() {
    //mSP.Write("1", 1);
}

Lights* Lights::GetInstance() {
    
    if (!mpLightsInstance) {
      mpLightsInstance = new Lights;
    }
    return mpLightsInstance;
}

void Lights::setMode(int mode) {
    //mSP.Write((char*)mode, 1);

    if (mode >= 0 || mode <= 8) {
        strMode[0] = mode + '0';
        mSP.Write(strMode, 64);
        printf("Writing to Arduino serial with mode %c\n", strMode[0]);
    } else {
        mSP.Write("0", 64);
        printf("Unknown/unused serial code used.\n");
    }

}

int Lights::getGyroAngle() {
    gyroVal = 0;
    negativeGyro = false;
    while (mSP.GetBytesReceived() >= 1) {
        mSP.Read(readBuffer, 25);
    }
    for (int i = 0; i < 25 && readBuffer[i] != 0; i++) {
        if (readBuffer[i] == '-') {
            negativeGyro = true;
        }
        else if (readBuffer[i] == '.') {
            return gyroVal;
        }
        else if (readBuffer[i] >= '0' && readBuffer[i] <= '9') {
            gyroVal *= 10;
            gyroVal += readBuffer[i];
        }
    }
}