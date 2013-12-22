#ifndef AUTOAIM_H
#define AUTOAIM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jarrett
 */
class AutoAim: public CommandBase {
	double lastPosition;
	double nextRunTime;
public:
	AutoAim();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
