/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include <frc/TimedRobot.h>
#include <frc/Compressor.h>

#include "OI.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/shuffleboard/Shuffleboard.h>

class Robot : public frc::TimedRobot
{
public:
  nt::NetworkTableEntry xEntry;
  nt::NetworkTableEntry yEntry;
  nt::NetworkTableEntry InchesToGoForward;

  // shuffleboard::Shuffleboardtab x;

  double x;
  double y;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void UpdateStatus();

private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Compressor *c;

  frc::Command *m_autonomousCommand = nullptr;
};
