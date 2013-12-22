#ifndef AXEL_SPEED_H
#define AXEL_SPEED_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jarrett
 */
class AxelSpeed: public CommandBase {
public:
	AxelSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	
};

#endif
