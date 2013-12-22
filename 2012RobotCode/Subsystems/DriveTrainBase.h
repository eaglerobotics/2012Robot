#ifndef DRIVETRAINBASE_H
#define DRIVETRAINBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class DriveTrainBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	float headingHold();
public:
	DriveTrainBase();
	void InitDefaultCommand() {}
	virtual void mecanumDrive_Polar(float direction, float power);
	virtual void mecanumDrive_Cartesian(float x, float y, float rotation);
	virtual float getGyroAngle() { return 0; }
	virtual void autoLevel();

	virtual void fineTrimLeft();
	virtual void coarseTrimLeft();
	virtual void fineTrimRight();
	virtual void coarseTrimRight();
	virtual void zeroGyro();
	virtual void ToggleTwistDisabled();
	virtual float GetGyroAngle();
};

#endif
