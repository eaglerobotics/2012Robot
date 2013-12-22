#ifndef FANBASE_H
#define FANBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class FanBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	FanBase();
	void InitDefaultCommand();
	virtual int RunFan() { return 0; }
};

#endif
