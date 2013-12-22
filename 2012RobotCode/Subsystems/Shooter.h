#ifndef SHOOTER_H
#define SHOOTER_H
#include "ShooterBase.h"
#include "WPILib.h"

class Shooter: public ShooterBase {
public:
	Victor *topAxel;
	Victor *bottomAxel;
	Encoder *topAxelEncoder;
	Encoder *bottomAxelEncoder;
	SendablePIDController *pidTopAxel;
	SendablePIDController *pidBottomAxel;
//	Victor *conveyorBelt;
		
public:
	Shooter();
	virtual void InitDefaultCommand();
	virtual void SetRange(float distance);
	virtual void TopAxelPID();
	virtual void BottomAxelPID();
	virtual void SetTopAxel(float fShooterSpeed);
	virtual void SetBottomAxel(float fShooterSpeed);
//	virtual void MoveConveyor();
//	virtual bool IsBallPrimed();
	// Review: See if the SendablePIDController can work
//	virtual SendablePIDController *getTopAxelPID();
//	virtual SendablePIDController *getBottomAxelPID();
	virtual void SetPowerAll(float power);
		
};

#endif
