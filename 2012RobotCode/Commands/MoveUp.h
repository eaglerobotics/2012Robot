#ifndef MOVEUP_H
#define MOVEUP_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Davey
 */
class MoveUp: public CommandBase {
private:
	int targetslot;
	bool waitForClear;
	bool safety;
public:
	MoveUp(bool SafetyEnabled=true);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
