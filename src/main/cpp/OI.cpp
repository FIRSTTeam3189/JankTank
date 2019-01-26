/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "Commands/EncoderReset.h"
#include "Commands/PistonBackToggle.h"
#include "Commands/PistonFrontToggle.h"
OI::OI() {

  }

  double OI::getLeftY(){
   return leftJoystick.GetY(frc::GenericHID::JoystickHand::kLeftHand);
    }

  double OI::getRightY(){
    return rightJoystick.GetY(frc::GenericHID::JoystickHand::kRightHand);
  }  
  void OI::InitHardware(){
    leftButton7 = new frc::JoystickButton(&leftJoystick, 8);
    leftButton7 = new frc::JoystickButton(&leftJoystick,7);
    leftButton6 = new frc::JoystickButton(&leftJoystick,6);

    leftButton8->WhenPressed(new PistonFrontToggle());
    leftButton7->WhenPressed(new EncoderReset());
    leftButton6->WhenPressed(new PistonBackToggle());
  }
  // Process operator interface input here.

