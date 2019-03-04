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
#include "Utils/Piston.h"
#include <frc/Solenoid.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <networktables/NetworkTable.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/DigitalInput.h>
using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
class Drivetrain : public frc::Subsystem
{
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  CANTalon *frontLeft;
  CANTalon *frontRight;
  CANTalon *backLeft;
  CANTalon *backRight;
  Piston *back_pistons;
  Piston *front_pistons;
  frc::Solenoid *solenoid1;
  frc::DigitalInput *limitSwitchUpper;
  frc::DigitalInput *limitSwitchLower;
  //  frc::ShuffleboardTab::ShuffleboardTab tab;
  // nt::NetworkTableEntry x;

  // frc::Encoder *encoder1;

public:
  Drivetrain();
  void InitDefaultCommand() override;
  void Drive(double left, double right);
  double GetDistance();
  double GetEncoder();
  void ToggleBackPistons();
  void ToggleFrontPistons();
  void ResetEncoders();
  void InitHardware();
  void DriveDistance(double distanceL, double distanceR);
  double GetEncoderLeftDistance();
  double GetEncoderRightDistance();
  void UpdateStatus();
};
