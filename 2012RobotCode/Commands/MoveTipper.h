#ifndef MOVETIPPER_H
#define MOVETIPPER_H

#include "../CommandBase.h"
#include "../SubSystems/Tipper.h"

/**
 *
 *
 * @author ag291863
 */
class MoveTipper: public CommandBase {
private:
	Tipper::tipperMode mode;
	
	
public:
	
	MoveTipper(Tipper::tipperMode);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
