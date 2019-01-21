/*
 * Piston.h
 *
 *  Created on: Jan 9, 2018
 *      Author: Everybody
 */

#ifndef PISTON_H_
#define PISTON_H_

#include <WPILib.h>
#include <frc/Solenoid.h>

struct PistonData{
	int deviceID;
	int retractID;
	int extendID;
	int extendedByDefault;
	PistonData(int extendID, int retractID, int deviceID = 0, bool extended = false);
};

class Piston {
protected:
	frc::Solenoid* extended;
public:

	/**
	 * Channels air into The extension of piston.
	 */
	virtual void Extend() = 0;

	/**
	 * Channels air into the Retraction of piston
	 */
	virtual void Retract() = 0;

	/**
	 * Toggles the state of the piston.f
	 */
	virtual void Toggle() = 0;
};

class PistonSingle: public Piston {
public:
	PistonSingle(int extendID, int deviceID, bool extended = false);
	PistonSingle(PistonData init);

	/**
	 * Channels air into The extension of piston.
	 */
	virtual void Extend();

	/**
	 * Channels air into the Retraction of piston
	 */
	virtual void Retract();

	/**
	 * Toggles the state of the piston.f
	 */
	virtual void Toggle();
};

class PistonDouble: public Piston {
protected:
	frc::Solenoid* retracted;
public:
	/**
	 * Provides interface for Pistons
	 * @param extendID Device ID for extended solenoid
	 * @param retractID Device ID for retracted solenoid
	 * @param extended the default state of the piston
	 */
	PistonDouble(int extendID, int retractID, int deviceID,bool extended = false);
	PistonDouble(int extendID, int retractID,bool extended = false);
	PistonDouble(PistonData init);

	/**
	 * Channels air into The extension of piston.
	 */
	virtual void Extend();

	/**
	 * Channels air into the Retraction of piston
	 */
	virtual void Retract();

	/**
	 * Toggles the state of the piston.f
	 */
	virtual void Toggle();
};

#endif /* PISTON_H_ */
