#ifndef NOBALLCOLLETION_H
#define NOBALLCOLLETION_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Davey
 */
class NoBallColletion: public CommandBase {
public:
	NoBallColletion();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
