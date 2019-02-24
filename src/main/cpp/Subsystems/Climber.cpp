/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/*
#include "Subsystems/Climber.h"
#include "RobotMap.h"

Climber::Climber() : Subsystem("Climber") {}

void Climber::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
//extends the two back pistons on the robot
void Climber::PistonsBackExtend()
{

  backRightPiston->Extend();
}
//retracts the two back pistons on the robot
void Climber::PistonsBackRetract()
{

  backRightPiston->Retract();
}
//extends the two pistons on the front of the robot
void Climber::PistonsFrontExtend()
{
 
  frontRightPiston->Extend();
}
//retracts the two front pistons on the fron of the robot
void Climber::PistonsFrontRetract()
{
  
  frontRightPiston->Retract();
}
//initilizes the pistons for the climber and assigns their ports on the pnumatic control module (PCM).
//Called in Robot.cpp in RobotInit
void Climber::InitHardware()
{
  frontRightPiston = new PistonDouble(CLIMBER_PISTONS_FRONT_RETRACT, CLIMBER_PISTONS_FRONT_EXTEND, CLIMBER_SOLENOID_PCM_ID);
  backRightPiston = new PistonDouble(CLIMBER_PISTONS_BACK_EXTEND, CLIMBER_PISTONS_BACK_RETRACT, CLIMBER_SOLENOID_PCM_ID);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
*/