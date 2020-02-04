/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ServoCamera.h"
#include <frc/Servo.h>
ServoCamera::ServoCamera():
    exampleServo{1}
{


}

// This method will be called once per scheduler run
void ServoCamera::Periodic() {}

void ServoCamera::setPosition(float x){
    exampleServo.Set(x);
}