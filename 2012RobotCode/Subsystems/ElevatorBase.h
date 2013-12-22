#ifndef ELEVATORBASE_H
#define ELEVATORBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Davey
 */
class ElevatorBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	typedef enum elevatorMode {
			moveUp,
			moveDown,
			stop
	};
	
	ElevatorBase();
	virtual void InitDefaultCommand();
	virtual void moveElevator(elevatorMode mode);
	virtual bool isBallSlot1();
	virtual bool isBallSlot2();
	virtual bool isBallSlot3();
	virtual bool isBallSweeperArea();
};

#endif
