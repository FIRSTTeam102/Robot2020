/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>
#include <frc/XboxController.h>

class AnalogButton : public frc2::Button {
 public:
  AnalogButton(frc::XboxController* xboxControl, frc::XboxController::JoystickHand stickHand);

  bool Get() const override {
     return(mpXboxControl->GetTriggerAxis(mStickHand)>=mThreshold);};
  void setThreshold(double threshold){mThreshold=threshold;};

 private:
   frc::XboxController* mpXboxControl;
   frc::XboxController::JoystickHand mStickHand;
   double mThreshold = 0.5;
};
