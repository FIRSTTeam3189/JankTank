/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/PistonToggle.h"

PistonToggle::PistonToggle() : CommandBase("PistonToggle") {
  Requires(CommandBase::drivetrain.get());
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PistonToggle::Initialize() {
  drivetrain->TogglePiston();
}

// Called repeatedly when this Command is scheduled to run
void PistonToggle::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool PistonToggle::IsFinished() { return true; }

// Called once after isFinished returns true
void PistonToggle::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PistonToggle::Interrupted() {}
