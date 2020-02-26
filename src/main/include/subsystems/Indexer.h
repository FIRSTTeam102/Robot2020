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
#include "Constants.h"

//Spins 760 rpms (diameter 1.5"), bottom sensor ~2" in
//Need a timeout so they are indexed far enough

class Indexer : public frc2::SubsystemBase {
 public:
  Indexer();
    bool isFullIndexer();
    bool isEmptyIndexer();
    int  numLoadedPowerCells() {return(mNumPowerCells);}
    void movePowerCellsToTop();
    void movePowerCellsToBottom();
    void shootPowerCells();
    bool isPowerCellAtTop(){return mTopSensor.Get();}
    bool isPowerCellAtBottom(){return mBottomSensor.Get();}
    bool isPowerCellAtIntake(){return (mIntakeSensor.Get() + 1) % 2;}
    void stopIndexer(){mIndexerConveyer.Set(frc::Relay::kOff);}
    void moveUpIndexer() {mIndexerConveyer.Set(frc::Relay::Value::kForward);}
    void moveDownIndexer() {mIndexerConveyer.Set(frc::Relay::kReverse);}
    void resetRunningOnEmpty() {mEmptyTimer = 0;}
    bool isRunningOnEmpty() {return (mEmptyTimer>=kMaxPowerCellTravelTime);}
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
  int mNumPowerCells;
  int mEmptyTimer;
  bool mPowerCellWasAtIntake;
};
