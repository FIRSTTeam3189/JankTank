/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CommandBase.h"


std::unique_ptr<Drivetrain> CommandBase::drivetrain = std::make_unique<Drivetrain>();
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

	CommandBase::CommandBase(const std::string& name) : frc::Command(name){
        
    }