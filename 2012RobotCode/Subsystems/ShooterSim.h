#ifndef SHOOTERSIM_H
#define SHOOTERSIM	_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ShooterBase.h"

class ShooterSim: public ShooterBase {
private:

		
public:
	ShooterSim();
	virtual void InitDefaultCommand();
	virtual void SetRange(float distance);
	virtual void TopAxelPID();
	virtual void BottomAxelPID();
	virtual void SetTopAxel(float fShooterSpeed);
	virtual void SetBottomAxel(float fShooterSpeed);
	virtual void MoveConveyor();
//	virtual SendablePIDController *getTopAxelPID();
//	virtual SendablePIDController *getBottomAxelPID();
		
};

#endif
