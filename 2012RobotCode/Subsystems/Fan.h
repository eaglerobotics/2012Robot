#ifndef FAN_H
#define FAN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "FanBase.h"

/**
 *
 *
 * @author Jarrett
 */
class Fan: public FanBase {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay *fan;
	
public:
	Fan();
	void InitDefaultCommand();
	int RunFan();
};

#endif
