/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/Drivetrain.h"
#include "RobotMap.h"
#include "Commands/Drive.h"
//#include <frc/Encoder.h>

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

}

void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new commands::Drive());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::Drive(double left, double right){
frontLeft->Set(ControlMode::PercentOutput,left);
frontRight->Set(ControlMode::PercentOutput,right);
}

double Drivetrain::GetDistance(){
 return (backRight->GetSelectedSensorPosition() + backLeft->GetSelectedSensorPosition(0))/2/160;
}

double Drivetrain::GetEncoder(){
 return encoder1->GetDistance();
}

void Drivetrain::ResetEncoders(){
  backRight->SetSelectedSensorPosition(0,0,0);
  backLeft->SetSelectedSensorPosition(0,0,0);
}

void Drivetrain::InitHardware(){
  //add values to robotmap
  frontLeft = new CANTalon(DRIVE_LEFT_FRONT);
  frontRight = new CANTalon( DRIVE_RIGHT_FRONT);
  backLeft = new CANTalon(DRIVE_LEFT_BACK);
  backRight = new CANTalon(DRIVE_RIGHT_BACK);

 encoder1 = new frc::Encoder(9,9);//,false,frc::CounterBase::k4X);

frontLeft->SetInverted(true);
backLeft->SetInverted(true);

backLeft->Set(ControlMode::Follower,frontLeft->GetDeviceID());
backRight->Set(ControlMode::Follower,frontRight->GetDeviceID());

backRight->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder,0,0);
backLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder,0,0);
frontLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder,0,0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
