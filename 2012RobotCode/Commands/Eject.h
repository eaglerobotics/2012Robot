#ifndef EJECT_H
#define EJECT_H

#include "../CommandBase.h"


/**
 *
 *
 * @author Davey
 */
class Eject: public CommandBase {
public:
	Eject();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
