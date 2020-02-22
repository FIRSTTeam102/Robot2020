/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include "Constants.h"

Shooter::Shooter() : 
    mShooter1{kFlyMotor1},
    mShooter2{kFlyMotor2}
{
    mShooter2.Set(ControlMode::Follower, kFlyMotor1);
    mShooter1.SetInverted(true);
    mShooter2.SetInverted(true);
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}

void Shooter::setSpeed(float speed) {
    mSpeed = speed;
}

void Shooter::startMotor() {
    printf("Set motor to %f\n", mSpeed);
    mShooter1.Set(mSpeed);
    mIsStarted = true;
}

void Shooter::stopMotor() {
    printf("Stopping motor\n");
    mShooter1.Set(0);
    mIsStarted = false;
}

bool Shooter::isRunning() {
    return mIsStarted;
}