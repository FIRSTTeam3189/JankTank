/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Drivetrain.h"
#include "RobotMap.h"
#include "Commands/TankDrive.h"
#include "Constants.h"
#include <frc/Encoder.h>

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{ /**
     frc::ShuffleboardTab::ShuffleboardTab &tab = frc::Shuffleboard::GetTab("Drive");
 nt::NetworkTableEntry maxSpeed =
      tab.Add("Max Speed", 1)
         .GetEntry();*/
}

void Drivetrain::InitDefaultCommand()
{
  SetDefaultCommand(new commands::TankDrive());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::Drive(double left, double right)
{
  backLeft-> Set(ControlMode::PercentOutput, left);
  backRight->Set(ControlMode::PercentOutput, right);
  //backLeft-> Set(ControlMode::PercentOutput, left);
  //backRight->Set(ControlMode::PercentOutput, right);
  //frc::SmartDashboard::PutNumber("power",frontRight->GetActiveTrajectoryVelocity());
}

//  Toggle the front or back pistons between (retracted / extended)
void Drivetrain::ToggleBackPistons() {back_pistons->Toggle();}
void Drivetrain::ToggleFrontPistons() {front_pistons->Toggle();}

//  Return the current encoder values for L and R encoders
double Drivetrain::GetEncoderLeftDistance(){return backLeft->GetSelectedSensorPosition(0);}
double Drivetrain::GetEncoderRightDistance(){return backRight->GetSelectedSensorPosition(0);}

void Drivetrain::ResetEncoders()
{ // Set Left and Right encoders to a known value (usually 0)
  backRight->SetSelectedSensorPosition(0, 0, 0);
  backLeft-> SetSelectedSensorPosition(0, 0, 0);
}

void Drivetrain::DriveDistance(double distanceL, double distanceR){
  // Drive the Left- and Right-side drivetrain motors for the desired encoder counts
  
  backLeft-> Set(ControlMode::Position,distanceL);
  backRight->Set(ControlMode::Position,distanceR);
}

void Drivetrain::InitHardware()
{
  limitSwitchUpper = new frc::DigitalInput(0);
  limitSwitchLower = new frc::DigitalInput(1);
  //  Add values to robotmap
  frontLeft =   new CANTalon(DRIVE_LEFT_FRONT);
  frontRight =  new CANTalon(DRIVE_RIGHT_FRONT);
  backLeft =    new CANTalon(DRIVE_LEFT_BACK);
  backRight =   new CANTalon(DRIVE_RIGHT_BACK);

  back_pistons =  new PistonDouble(PISTON_BACK_EXTEND, PISTON_BACK_RETRACT);
  front_pistons = new PistonDouble(PISTON_FRONT_EXTEND, PISTON_FRONT_RETRACT);

  // Set the left-side motors to run 'reverse' as they're mounted opposite
  frontLeft-> SetInverted(true);
  //backLeft->  SetInverted(true);
  frontRight -> SetInverted(true);
  // Set the back motors to mimic all commands sent to their respective forward motors
  frontLeft->  Set(ControlMode::Follower, backLeft->GetDeviceID());
  frontRight-> Set(ControlMode::Follower, backRight->GetDeviceID());

  // Setup the Left- and Right-side encoders
  frontRight->  ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
  frontLeft->   ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
/*
  // Set the constant Forward & reverse outputs (usually 0)
  frontRight->ConfigNominalOutputForward(0, 10);  // Constant forward motor output
  frontRight->ConfigNominalOutputReverse(0, 10);  // Constant reverse motor output
  frontRight->ConfigPeakOutputForward( 0.6, 10);  // Max forward motor output (?)
  frontRight->ConfigPeakOutputReverse(-0.6, 10);  // Max reverse motor output

  frontLeft->ConfigNominalOutputForward(0, 10); // Like the above 4, but for the left side
  frontLeft->ConfigNominalOutputReverse(0, 10);
  frontLeft->ConfigPeakOutputForward( 0.6, 10);
  frontLeft->ConfigPeakOutputReverse(-0.6, 10);

  frontRight->SelectProfileSlot(0, 0);        // Choose the 0-slot PID profile
  frontRight->Config_kF(0, DRIVETRAIN_F, 10); // Right-side PID feed-forward constant
  frontRight->Config_kP(0, DRIVETRAIN_P, 10); // Right-side Proportional constant
  frontRight->Config_kI(0, DRIVETRAIN_I, 10); // Integral constant
  frontRight->Config_kD(0, DRIVETRAIN_D, 10); // Derivative constant

  frontLeft->SelectProfileSlot(0, 0);         // Like the above 4, but for the Left side
  frontLeft->Config_kF(0, DRIVETRAIN_F, 10);
  frontLeft->Config_kP(0, DRIVETRAIN_P, 10);
  frontLeft->Config_kI(0, DRIVETRAIN_I, 10);
  frontLeft->Config_kD(0, DRIVETRAIN_D, 10);

  frontLeft->ConfigForwardLimitSwitchSource(ctre::phoenix::motorcontrol::RemoteLimitSwitchSource_RemoteTalonSRX, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0, 10);
  //  Sets the motor to stop when the top limit switch is triggered. Needs testinf because ^
  frontLeft->ConfigReverseLimitSwitchSource(ctre::phoenix::motorcontrol::RemoteLimitSwitchSource_RemoteTalonSRX, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 1, 10);
  */
  //frontLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
} // End InitHardware
// Put methods for controlling this subsystem
// here. Call these from Commands.
