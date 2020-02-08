/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Flywheel.h"
#include "Constants.h"

Flywheel::Flywheel() : 
    mFlyEnc{kFlyEncA, kFlyEncB, kReverseFlyEnc, kFlyEncType},
    mFlywheel{kFlyMotor}
{
    mFlyEnc.SetDistancePerPulse(1/360);
    mFlywheel.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
}

// This method will be called once per scheduler run
void Flywheel::Periodic() {}

void Flywheel::setSpeed(int speed) { //Takes in RPM
    targetRPS = speed / 60;
    targetRP100ms = targetRPS / 10;
}

void Flywheel::startMotor() {
    mFlywheel.Set(ControlMode::Velocity, targetRP100ms);
}

void Flywheel::stopMotor() {
    mFlywheel.Set(0);
}

bool Flywheel::isReady() {
    return (mFlyEnc.GetRate() >= targetRPS * 0.9);
}

int Flywheel::getRPM() {
    return mFlyEnc.GetRate() * 60;
}