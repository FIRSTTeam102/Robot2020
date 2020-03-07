/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CameraServo.h"
#include <frc/Servo.h>
CameraServo::CameraServo():
    mCameraServoX{kCameraServoXIndex}, mCameraServoY{kCameraServoYIndex}
{
    cameraServoXPosition = 0.5;
    cameraServoYPosition= 0.5;
}

// This method will be called once per scheduler run
void CameraServo::Periodic() {}
void CameraServo::controlServoWithJoystick()
{
    
    horizontalPower = mpServoJoystick->GetRawAxis(4);
    horizontalPower = horizontalPower/5;
    verticalPower = mpServoJoystick->GetRawAxis(5);
    verticalPower = verticalPower/5;
    if(cameraServoXPosition >= 1 && horizontalPower > 0){ //Prevents servo position from exceeding range
        return;
    }
    else if(cameraServoXPosition <= 0 && horizontalPower < 0){
       return;
    }
    else mCameraServoX.Set(cameraServoXPosition + horizontalPower);


    if(cameraServoYPosition >= 1 && verticalPower > 0){ //Prevents servo position from exceeding range
        return;
    }
    else if(cameraServoYPosition <= 0 && verticalPower < 0){
       return;
    }
    else mCameraServoY.Set(cameraServoXPosition + verticalPower );
}
