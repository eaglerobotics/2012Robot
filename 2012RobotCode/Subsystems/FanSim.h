#ifndef FANSIM_H
#define FANSIM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "FanBase.h"

/**
 *
 *
 * @author Jarrett
 */
class FanSim: public FanBase {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	FanSim();
	void InitDefaultCommand();
	virtual int RunFan();
};

#endif
