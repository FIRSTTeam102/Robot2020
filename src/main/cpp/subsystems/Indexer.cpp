/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "Constants.h"
#include "subsystems/Indexer.h"


Indexer::Indexer():
    mIndexerConveyer{kIndexChannel,frc::Relay::kBothDirections},
    mIntakeSensor{kDIOIntake},
    mBottomSensor{kDIOBottom},
    mTopSensor{kDIOTop},
    mnumPowerCells{3}
 {

}
//isFullIndexer - returns true if the TopSensor,
//   and IntakeSensor all see a power cell. The Indexer is
//   considered full if it can't move any balls up (they would enter
//   the shooter) and the intakeSensor has a ball (so it cannot move the 
//   conveyor at all).
bool Indexer::isFullIndexer(){
    if (mTopSensor.Get() && mIntakeSensor.Get()){
        return(true);
    }
    else {
        return(false);
    }
}
//isEmptyIndexer - determine if the indexer is empty. It has no power cells
//  if none of the sensors register a power cell, we could be in a state where
//  there are few balls (less than 3) in the indexer and they are traveling
//  either toward the top or the bottom. If this is the case we need to 
//  wait for the travel timer(time it takes for a ball to go the whole indexer
//  length) expires.
bool Indexer::isEmptyIndexer(){
    if (!isPowerCellAtTop() && !isPowerCellAtBottom()){
        if (mtravelTimer < kMaxPowerCellTravelTime){
            mtravelTimer++;
        }
        else {
            return(true);
        }
    }
    return(false);
}
//movePowerCellsToTop - move the line of power cells up to the top of
//   the indexer. This is helpful so shooting power cells can start
void Indexer::movePowerCellsToTop(){
    //if there is a ball in the top of the sensor, we are done.
    if (isPowerCellAtTop()){
        stopIndexer();
    }
    else { //try to move balls to the top of the indexer
        moveUpIndexer();
    }
}
//movePowerCellsToBottom - move all of the power cells down in
// the conveyor until the reach the Bottom Sensor
void Indexer::movePowerCellsToBottom(){
    if (isPowerCellAtBottom()){
        stopIndexer();
    } else{
        moveDownIndexer();
    }
}
//intakeAPowerCell - if a power cell is in the intake sensor, and the indexer
//  is not full, move it to the bottom position
void Indexer::intakeAPowerCell(){
    //ready to take in a new power cell
    if (!isFullIndexer() && isPowerCellAtIntake()){
        mpowerCellWasAtIntake = true;
        mnumPowerCells++;
        moveUpIndexer();
    }
    //power cell that was at the intake, see if it has made it
    //  see if it made it past the intake otherwise, keep running
    //  the indexer because the power cell is in transit to the bottom
    else if (!isPowerCellAtIntake() && mpowerCellWasAtIntake){
        //if the new power cell made it to the bottom sensor
        //  stop the indexer, until a new ball is in the intake
        //  don't let the intake continually run or the power cells
        //  will move up to fast, leaving spaces.
        if (isPowerCellAtBottom()){
            stopIndexer();
            mpowerCellWasAtIntake = false;
        }
    }
}
//Shoot Power cell - just move the indexer 
void Indexer::shootPowerCell(){
    moveUpIndexer();
    //how to keep track of counter here?
}
// This method will be called once per scheduler run
void Indexer::Periodic() {}
