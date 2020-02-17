/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SerialNano.h"

SerialNano::SerialNano(): mNanoSP{9600, frc::SerialPort::kUSB1} {
    mNanoSP.EnableTermination();
    mNanoSP.SetWriteBufferMode(frc::SerialPort::kFlushWhenFull);
}

// This method will be called once per scheduler run
void SerialNano::Periodic() {
    if (mNanoSP.GetBytesReceived() >= 1) {
        mNanoSP.Read(mBuffer, 100);
        printf("Nano - %s\n", mBuffer);
    }
}
