/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/Encoder.h>
using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode; 
class Drivetrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  CANTalon* frontLeft;
  CANTalon* frontRight;
  CANTalon* backLeft;
  CANTalon* backRight;
  frc::Encoder* encoder1;
 public:
  Drivetrain();
  void InitDefaultCommand() override;
  void Drive(double left, double right);
  double GetDistance();
  double GetEncoder();
  void ResetEncoders();
  void InitHardware();
};
