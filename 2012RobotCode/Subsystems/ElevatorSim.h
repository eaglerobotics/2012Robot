#ifndef ELEVATORSIM_H
#define ELEVATORSIM_H
#include "ElevatorBase.h"
#include "WPILib.h"

/**
 *
 *
 * @author Davey
 */
class ElevatorSim: public ElevatorBase {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ElevatorSim();
	void InitDefaultCommand();
};

#endif
