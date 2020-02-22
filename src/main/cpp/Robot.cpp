/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardWidget.h>
#include <frc2/command/CommandScheduler.h>
#include <cameraserver/CameraServer.h>
#include <rev/ColorMatch.h>


void Robot::RobotInit() {
  //Create autonomous command choices
  //Create Chooser for Autonomouse starting position
  
  mAutoPos.AddOption("In front of target", 1);
  mAutoPos.AddOption("In front of trench", 2);
  mAutoPos.AddOption("Far away", 3);

  //create chooser to take the shot or not at autonomous start
  
  mAutoShoot.AddOption("Shoot", true);
  mAutoShoot.AddOption("Don't Shoot", false);

  //create chooser for desired autonomous movement off the line
  
  mAutoMovement.AddOption("Pick up (trench only)", 1);
  mAutoMovement.AddOption("Back up", 2);
  mAutoMovement.AddOption("Delayed back up", 3);

  //create chooser - if trench balls were picked up, shoot them?
  
  mAutoShoot2.AddOption("Shoot trench balls", true);
  mAutoShoot2.AddOption("Don't shoot trench balls", false);

  //create chooser - Intake Test?

  mIntake.AddOption("Raise Arm", 1);
  mIntake.AddOption("Lower Arm", 2);
  mIntake.AddOption("Rollers Forward", 3);
  mIntake.AddOption("Rollers Reverse (Chacha real smooth)", 4);
  mIntake.AddOption("Stop Rollers", 5);

  //create chooser - Indexer Test?

  mIndexer.AddOption("Move Power Cells to Top", 1);
  mIndexer.AddOption("Move Power Cells to Bottom", 2);

  //create chooser - Shooter Test?

  mShooter.AddOption("Start Flywheel", 1);
  mShooter.AddOption("Stop Flywheel", 2);

  //create the autonomous command tab on the shuffleboard and add each
  // choosers widget, building the auto menu
  frc::Shuffleboard::GetTab("Auto")
    .Add("Starting Position",mAutoPos)
    .WithWidget(frc::BuiltInWidgets::kComboBoxChooser).WithSize(2, 1).WithPosition(7, 0);
  
  frc::Shuffleboard::GetTab("Auto")
    .Add("Initial Shot?",mAutoShoot)
    .WithWidget(frc::BuiltInWidgets::kSplitButtonChooser).WithSize(2, 1).WithPosition(7, 2);
  
  frc::Shuffleboard::GetTab("Auto")
    .Add("Movement",mAutoMovement)
    .WithWidget(frc::BuiltInWidgets::kComboBoxChooser).WithSize(2, 1).WithPosition(7, 1);
  
  frc::Shuffleboard::GetTab("Auto")
    .Add("Shoot Again?",mAutoShoot2)
    .WithWidget(frc::BuiltInWidgets::kSplitButtonChooser).WithSize(3, 1).WithPosition(7, 3);
  
  //Tab Test
  frc::Shuffleboard::GetTab("TestRobot")
    .Add("Intake Test Bin?",mIntake)
    .WithWidget(frc::BuiltInWidgets::kComboBoxChooser).WithSize(3, 1).WithPosition(1, 1);

  frc::Shuffleboard::GetTab("TestRobot")
    .Add("Indexer Test Bin?",mIndexer)
    .WithWidget(frc::BuiltInWidgets::kComboBoxChooser).WithSize(3, 1).WithPosition(1, 2);

  frc::Shuffleboard::GetTab("TestRobot")
    .Add("Shooter Bin?",mShooter)
    .WithWidget(frc::BuiltInWidgets::kComboBoxChooser).WithSize(3, 1).WithPosition(1, 3);

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
