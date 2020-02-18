/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PixyCam.h"
#include <frc/SerialPort.h>

PixyCam::PixyCam(): mPixyArduino{115200, frc::SerialPort::kUSB, 8, frc::SerialPort::kParity_None, frc::SerialPort::kStopBits_One} {
    mPixyArduino.Reset();
    mPixyArduino.EnableTermination();
    mPixyArduino.SetWriteBufferMode(frc::SerialPort::kFlushWhenFull);
}

void PixyCam::printWidth(){

}


// This method will be called once per scheduler run
void PixyCam::Periodic() {
    printf("running printwidth\n");
    //mPixyArduino.Write("Begin\n");
    if (mPixyArduino.GetBytesReceived() >= 1) {
        printf("SIGNAL RECIEVED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n");
        mPixyArduino.Read(buffer, 100);
        printf("%s\n", buffer);
    }
    else {
        printf("No data\n");
    }
}
