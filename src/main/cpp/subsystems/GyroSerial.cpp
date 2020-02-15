/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/GyroSerial.h"

GyroSerial::GyroSerial(): mSerial{9600, kGyroSerial} {
    mSerial.EnableTermination('\n');
    mSerial.Write("Begin");
}

// This method will be called once per scheduler run
void GyroSerial::Periodic() {}

int GyroSerial::getAngle() {
    if (mSerial.GetBytesReceived() != 0) {
        angle = 0;
        for (int i = 0; i < 10; i++) {
            if (rawData[i] == '.') {
                break;
            }
            else if (rawData[i] == '-') {
                negativeAngle = true;
            }
            else {
                angle *= 10;
                angle += rawData[i] - '0';
            }
        }
    }
    else {
        mSerial.Write("");
    }
    return angle;
}