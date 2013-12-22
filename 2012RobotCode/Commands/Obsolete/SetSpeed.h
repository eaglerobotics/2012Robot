#ifndef Set_Speed_H
#define Set_Speed_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SetSpeed: public CommandBase {
public:
	SetSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
