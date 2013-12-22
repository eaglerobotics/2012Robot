#ifndef SHOOTERBASE_H
#define SHOOTERBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class ShooterBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterBase();
	void InitDefaultCommand();
	virtual void SetRange(float distance);
	virtual void TopAxelPID();
	virtual void BottomAxelPID();
	virtual void SetTopAxel(float fShooterSpeed);
	virtual void SetBottomAxel(float fShooterSpeed);
	virtual void MoveConveyor();
//	virtual SendablePIDController *getTopAxelPID();
//	virtual SendablePIDController *getBottomAxelPID();
	virtual void SetPowerAll(float power);
};

#endif
