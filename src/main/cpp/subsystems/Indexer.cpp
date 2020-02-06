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
    m_IndexerConveyer{kIndexChannel,frc::Relay::kBothDirections},
    m_IntakeSensor{kDIOIntake},
    m_BottomSensor{kDIOBottom},
    m_TopSensor{kDIOTop}
 {

}

// This method will be called once per scheduler run
void Indexer::Periodic() {



}
