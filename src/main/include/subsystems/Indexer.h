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
//Band moves 60"/s
//Ball moves 19"/s
//Timeout = gap + 7" - 2" = gap + 5"       7" for ball, sensor is 2" in already
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
    bool isPowerCellAtTop(){return !mTopSensor.Get();}
    bool isPowerCellAtBottom();
    //bool isPowerCellAtIntake(){return (!mIntakeSensor.Get()}
    bool isPowerCellAtIntake(){return !mIntakeSensor.Get();}
    bool rawPowerCellAtBottom(){return mBottomSensor.Get();}
    void stopIndexer(){mIndexerConveyer.Set(frc::Relay::kOff);}
    void moveUpIndexer() {mIndexerConveyer.Set(frc::Relay::Value::kForward);}
    void moveDownIndexer() {mIndexerConveyer.Set(frc::Relay::kReverse);}
    void resetRunningOnEmpty() {mEmptyTimer = 0;}
    bool isRunningOnEmpty() {return (mEmptyTimer>=kMaxPowerCellTravelTime);}
    void enable() {enabled = true;}
    void disable() {enabled = false;}
    bool isEnabled() {return enabled;}
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
  double mBottomTimer;
  bool mPowerCellWasAtIntake;
  bool mPowerCellWasAtBottom;
  bool enabled;
};
