/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/GoForwardEncoder.h"
GoForwardEncoder::GoForwardEncoder(double inputDistance) : CommandBase("GoForwardEncoder") {
  Requires(CommandBase::drivetrain.get());
  this->desiredDistance = inputDistance;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void GoForwardEncoder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void GoForwardEncoder::Execute() {
  CommandBase::drivetrain->Drive(0.2,0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool GoForwardEncoder::IsFinished() { return desiredDistance <= CommandBase::drivetrain->GetDistance(); }

// Called once after isFinished returns true
void GoForwardEncoder::End() {
  CommandBase::drivetrain->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoForwardEncoder::Interrupted() {
  CommandBase::drivetrain->Drive(0,0);
}
