/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Constants.h"


DriveTrain::DriveTrain():
    mDriveLeft1{kTopLeftMotor}, 
    mDriveLeft2{kBottomLeftMotor}, 
    mDriveRight1{kTopRightMotor}, 
    mDriveRight2{kBottomRightMotor}
 {
    mDriveLeft1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mDriveLeft2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mDriveRight1.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mDriveRight2.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}

void DriveTrain::tankDrive(){
    
    double leftSpeed = mpDriverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rightSpeed = mpDriverJoystick->GetRawAxis(5); //Cap: 697rpm
    if (!inverted) {
        mDrive.TankDrive(-leftSpeed,-rightSpeed,true);
    }
    else {
        mDrive.TankDrive(rightSpeed, leftSpeed, true);
    }
    //printf("Driving: %f, %f\n", leftSpeed, rightSpeed);
}

void DriveTrain::arcadeDrive(){
    double speed = mpDriverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rotation = mpDriverJoystick->GetRawAxis(4); //Cap: 697rpm
    if (!inverted) {
        mDrive.ArcadeDrive(-speed, rotation, true);
    }
    else {
        mDrive.ArcadeDrive(speed, -rotation, true);
    }
}

void DriveTrain::slowlyDriveForwards(){
    mDrive.TankDrive(0.2, 0.2, false);
}

void DriveTrain::stop(){
    mDrive.TankDrive(0, 0, false);
}

void DriveTrain::move(double left, double right){
    mDrive.TankDrive(left, right, false);
}

void DriveTrain::toggleDrive(){
    printf("On: %d\n", on);
    if (on == true) {
        mDrive.TankDrive(-1, -1, true);
        if (mpDriverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = false;
        }
    }
    else {
        mDrive.TankDrive(0, 0, true);
        if (mpDriverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = true;
        }
    }
}

bool DriveTrain::flipDrive() {
    if (inverted) {
        inverted = false;
    }
    else {
        inverted = true;
    }
    return inverted;
}