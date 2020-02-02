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
    driveLeft1{1}, 
    driveLeft2{2}, 
    driveRight1{3}, 
    driveRight2{4}
    {

}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {



}

void DriveTrain::driveWithXboxController(){
    
    double leftSpeed = p_driverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rightSpeed = p_driverJoystick->GetRawAxis(5); //Cap: 697rpm
    
    Drive.TankDrive(-leftSpeed,-rightSpeed,true);
    printf("Driving: %f, %f\n", leftSpeed, rightSpeed);

}

void DriveTrain::slowlyDriveForwards(){
    Drive.TankDrive(0.2, 0.2, false);
}

void DriveTrain::toggleDrive(){
    printf("On: %d\n", on);
    if (on == true) {
        Drive.TankDrive(-1, -1, true);
        if (p_driverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = false;
        }
    }
    else {
        Drive.TankDrive(0, 0, true);
        if (p_driverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = true;
        }
    }
}