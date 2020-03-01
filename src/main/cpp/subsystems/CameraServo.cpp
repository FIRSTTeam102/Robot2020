/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CameraServo.h"
#include <frc/Servo.h>
CameraServo::CameraServo():
    mCameraServo{kCameraServoIndex}
{

}

// This method will be called once per scheduler run
void CameraServo::Periodic() {}
void CameraServo::controlServoWithJoystick(){
    horizontalPower = (mpServoJoystick->GetRawAxis(0)/50);
    if(cameraServoPosition <= 0 && horizontalPower > 0){ //Prevents servo position from exceeding range
        return;
    }
    if(cameraServoPosition >= 1 && horizontalPower < 0){
        return;
    }
    mCameraServo.Set(cameraServoPosition + horizontalPower );
}