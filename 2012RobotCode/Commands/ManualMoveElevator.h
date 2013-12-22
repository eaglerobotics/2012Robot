#ifndef MANUALMOVEELEVATOR_H
#define MANUALMOVEELEVATOR_H

#include "../CommandBase.h"
#include "../SubSystems/Elevator.h"

/**
 *
 *
 * @author Davey
 */
class ManualMoveElevator: public CommandBase {
	
private:
	Elevator::elevatorMode mode;
	
public:
	ManualMoveElevator(Elevator::elevatorMode);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
