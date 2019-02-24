/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/GoForwardEncoder.h"
#include "Constants.h"
#include "CommandBase.h"
#include <stdlib.h>
#include <iostream>

GoForwardEncoder::GoForwardEncoder(double inputDistance) : CommandBase("GoForwardEncoder") {
  Requires(CommandBase::drivetrain.get());
  this->desiredDistance = inputDistance;//if you want inches, reinstate this line.: * TICKS_PER_REVOLUTION;
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
} // End Constructor

// Called just before this Command runs the first time
void GoForwardEncoder::Initialize() {
  // Get the current encoder values from Left and Right, add the new distance
  desiredDistanceL += CommandBase::drivetrain->GetEncoderLeftDistance();
  desiredDistanceR += CommandBase::drivetrain->GetEncoderRightDistance();

  std::cout << "\n\nBeginning PID movement.\nDesired setpoints: " << std::endl;
  std::cout << "Left: " << desiredDistanceL << "\nRight: " << desiredDistanceR << std::endl;

  CommandBase::drivetrain->DriveDistance(desiredDistanceL, desiredDistanceR);
} // End Initialize

// Called repeatedly when this Command is scheduled to run
void GoForwardEncoder::Execute() {
 // CommandBase::drivetrain->Drive(AUTO_FORWARD_SPEED,AUTO_FORWARD_SPEED);
} // End Execute

// Make this return true when this Command no longer needs to run execute()
bool GoForwardEncoder::IsFinished() { 
  // checks if both encoders have reached desired distance, returns true if so.
  
  //  Note: It's generally a better idea to break this down into several sub-functions
  //  For example: have a function to check if one encoder is within tolerance,
  //  and then use 2 instances of that function, AND-ed together here.
  //  So it would look like "return (isLeftFinished() && isRightFinished());"
  return ((fabs(CommandBase::drivetrain->GetEncoderLeftDistance()
      - desiredDistance) < DRIVETRAIN_PID_TOLERANCE )
   && (fabs(CommandBase::drivetrain->GetEncoderRightDistance()
      - desiredDistance) < DRIVETRAIN_PID_TOLERANCE));
} // End isFinished

// Called once after isFinished returns true
void GoForwardEncoder::End() {
  CommandBase::drivetrain->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoForwardEncoder::Interrupted() {
  CommandBase::drivetrain->Drive(0,0);
}