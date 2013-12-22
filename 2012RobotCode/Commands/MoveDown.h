#ifndef MOVEDOWN_H
#define MOVEDOWN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Davey
 */
class MoveDown: public CommandBase {
private:
	Timer timer;
	int targetslot;
	bool waitForClear;
public:
	MoveDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
