/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>
#include <string>
#include <frc/Commands/Command.h>
#include "Subsystems/Drivetrain.h"
#include "OI.h"
class CommandBase : public frc::Command {
 public:
 	CommandBase(const std::string& name);
  CommandBase() = default;

static std::unique_ptr<Drivetrain> drivetrain;
static std::unique_ptr<OI> oi;
};
