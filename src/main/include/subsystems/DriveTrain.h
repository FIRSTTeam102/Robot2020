/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Joystick.h>



class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  void driveWithXboxController();
  void setDriverJoystick(frc::Joystick* driverJoystick){
    p_driverJoystick = driverJoystick;
  };

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();



 private:

frc::Joystick* p_driverJoystick;

 WPI_TalonSRX driveLeft1;
 WPI_TalonSRX driveLeft2;
 WPI_TalonSRX driveRight1;
 WPI_TalonSRX driveRight2;

 frc::SpeedControllerGroup left{driveLeft1, driveLeft2};
 frc::SpeedControllerGroup right{driveRight1, driveRight2};

 frc::DifferentialDrive Drive{left, right};


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
