#ifndef AXEL_SPEED_H
#define AXEL_SPEED_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jarrett
 */
class TurretPIDChange: public CommandBase {
public:
	float dP, dI, dD;
	
	TurretPIDChange(float dP, float dI, float dD);
	virtual void Execute();
	virtual bool IsFinished() { return true; }
	virtual void Initialize() {}
	virtual void End() {}
	virtual void Interrupted() {}
private:
	
};

#endif
