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
#include "Commands/GoForwardEncoder.h"
#include "Commands/ClimbAuto.h"
OI::OI() {

  }

  double OI::getLeftY(){
   return leftJoystick.GetY(frc::GenericHID::JoystickHand::kLeftHand);
    }

  double OI::getRightY(){
    return rightJoystick.GetY(frc::GenericHID::JoystickHand::kRightHand);
  }
    
  void OI::InitHardware(){
    leftButton8 = new frc::JoystickButton(&leftJoystick, 8);
    leftButton7 = new frc::JoystickButton(&leftJoystick,7);
    leftButton6 = new frc::JoystickButton(&leftJoystick,6);
    leftButton2 = new frc::JoystickButton(&leftJoystick, 2);
    leftButton3 = new frc::JoystickButton(&leftJoystick, 3);
    rightButton3 = new frc::JoystickButton(&rightJoystick, 3);

    leftButton3->WhenPressed(new PistonFrontToggle());
    leftButton6->WhenPressed(new EncoderReset());
    rightButton3->WhenPressed(new PistonBackToggle());
    leftButton2->WhenPressed(new GoForwardEncoder(300));
    leftButton8->WhenPressed(new ClimbAuto());
  }
  // Process operator interface input here.

