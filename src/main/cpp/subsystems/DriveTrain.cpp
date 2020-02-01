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
    driveLeft1{k_topLeftMotor}, 
    driveLeft2{k_bottomLeftMotor}, 
    driveRight1{k_topRightMotor}, 
    driveRight2{k_bottomRightMotor}
 {

}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {



}

void DriveTrain::driveWithXboxController(){
    
    double leftSpeed = p_driverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rightSpeed = p_driverJoystick->GetRawAxis(5); //Cap: 697rpm
    
    Drive.TankDrive(-leftSpeed,-rightSpeed,true);
    printf("%f, %f\n", leftSpeed, rightSpeed);

}

void DriveTrain::arcadeDrive(){
    double speed = p_driverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rotation = p_driverJoystick->GetRawAxis(4); //Cap: 697rpm

    Drive.ArcadeDrive(speed,rotation);
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