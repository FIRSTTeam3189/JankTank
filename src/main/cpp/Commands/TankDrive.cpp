/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TankDrive.h"
#include "CommandBase.h"

commands::TankDrive::TankDrive() : CommandBase("TankDrive") {
  Requires(drivetrain.get());
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void commands::TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void commands::TankDrive::Execute()
{
  drivetrain->Drive(oi->getLeftY() * fabs(oi->getLeftY()), oi->getRightY() * fabs(oi->getRightY()));
  //drivetrain->Drive(oi->getLeftY(),oi->getRightY());
}

// Make this return true when this Command no longer needs to run execute()
bool commands::TankDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void commands::TankDrive::End() { drivetrain->Drive(0, 0); }

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void commands::TankDrive::Interrupted() { drivetrain->Drive(0, 0); }
