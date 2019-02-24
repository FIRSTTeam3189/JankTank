/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include "CommandBase.h"
#include <pathfinder.h>
#include <frc/SerialPort.h>
#include <iostream>

void Robot::RobotInit()
{
  std::cout << "Robot initializing..." << std::endl;

  //  Initialize subsystem hardware
  CommandBase::drivetrain->InitHardware();
  CommandBase::oi->InitHardware();
  //std::cout << "test";

  //  Setup the compressor
  c = new frc::Compressor(0);
  c->SetClosedLoopControl(true);

  //  Whatever this is.
  Robot::x = 0;
  Robot::y = 0;
 
  //  SmartDashBoard testing here
  testEntry = tab.AddPersistent("test", 1.0).GetEntry();
  auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("datatable");

  xEntry = table->GetEntry("X");
  yEntry = table->GetEntry("Y");
  // frc::SerialPort::SerialPort port = new SerialPort::SerialPort(2,kOnboard,8,kParity_None,kStopBits_One)
  std::cout << "Robot initialization finished." << std::endl;
} // End RobotInit

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  tickCount++;
  if (tickCount == 25)
  { // Only update every few ticks. Note that each tick is ~20ms.
    std::cout << "\nLeft Encoder: " << CommandBase::drivetrain->GetEncoderLeftDistance() << std::endl;
    std::cout << "Right Encoder: "  << CommandBase::drivetrain->GetEncoderRightDistance() << std::endl;
    tickCount = 0;
  }
} // End RobotPeriodic

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic()
{
  frc::Scheduler::GetInstance()->Run();
  UpdateStatus();
} // End DisabledPeriodic

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }

  if (m_autonomousCommand != nullptr)
  {
    m_autonomousCommand->Start();
  }
} // End AutonomousInit

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit()
{
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr)
  {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  std::cout << "Teleop initialized." << std::endl;
} // End TeleopInit

void Robot::TeleopPeriodic()
{
  frc::Scheduler::GetInstance()->Run();
  UpdateStatus();
  // xEntry.setDouble("test",x);
  yEntry.SetDouble(y);
  xEntry.SetDouble(x);

  x += 0.05;
  y += 1.0;
} // End TeleopPeriodic

void Robot::TestPeriodic() {}

void Robot::UpdateStatus()
{
  /*frc::SmartDashboard::PutNumber("left Y ", CommandBase::oi->getLeftY());
  frc::SmartDashboard::PutNumber("left quadratic ", CommandBase::oi->getLeftY() * fabs(CommandBase::oi->getLeftY()));
  frc::SmartDashboard::PutNumber("encoders", CommandBase::drivetrain->GetDistance());
  frc::SmartDashboard::PutNumber("Dev's special encoder buddy", CommandBase::drivetrain->GetEncoder());*/
 // testEntry.SetDouble(420.6969);
  frc::SmartDashboard::PutNumber("MURDER!!!",testEntry.GetDouble(0));
} // End UpdateStatus

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif
