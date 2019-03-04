/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
class OI
{
public:
  OI();
  void InitHardware();
  double getRightY();
  double getLeftY();

private:
  frc::Joystick leftJoystick{0};
  frc::Joystick rightJoystick{1};

  frc::JoystickButton *leftButton8;
  frc::JoystickButton *leftButton7;
  frc::JoystickButton *leftButton6;
  frc::JoystickButton *leftButton2;
  frc::JoystickButton *leftButton3;
  frc::JoystickButton *rightButton3;
};
