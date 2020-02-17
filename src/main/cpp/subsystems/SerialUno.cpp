/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SerialUno.h"

SerialUno::SerialUno(): mUnoSP{57600, frc::SerialPort::kUSB2} {
    mUnoSP.EnableTermination();
    mUnoSP.SetWriteBufferMode(frc::SerialPort::kFlushWhenFull);
}

// This method will be called once per scheduler run
void SerialUno::Periodic() {
    if (mUnoSP.GetBytesReceived() >= 1) {
        mUnoSP.Read(mBuffer, 100);
        printf("Uno - %s\n", mBuffer);
    }
}
