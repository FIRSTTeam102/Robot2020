/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include "Constants.h"

Shooter::Shooter() : 
    mFlyEnc{kFlyEncA, kFlyEncB, kReverseFlyEnc, kFlyEncType},
    mShooter{kFlyMotor}
{
    mFlyEnc.SetDistancePerPulse(1/360);
    mShooter.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}

void Shooter::setSpeed(int speed) { //Takes in RPM
    targetRPS = speed / 60;
    targetRP100ms = targetRPS / 10;
}

void Shooter::startMotor() {
    mShooter.Set(ControlMode::Velocity, targetRP100ms);
}

void Shooter::stopMotor() {
    mShooter.Set(0);
}

bool Shooter::isReady() {
    return (mFlyEnc.GetRate() >= targetRPS * 0.9);
}

int Shooter::getRPM() {
    return mFlyEnc.GetRate() * 60;
}