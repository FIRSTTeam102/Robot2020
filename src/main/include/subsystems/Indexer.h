/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Relay.h>
#include <frc/DigitalInput.h>



class Indexer : public frc2::SubsystemBase {
 public:
  Indexer();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Relay mIndexerConveyer;
  frc::DigitalInput mIntakeSensor;
  frc::DigitalInput mBottomSensor;
  frc::DigitalInput mTopSensor;
};
