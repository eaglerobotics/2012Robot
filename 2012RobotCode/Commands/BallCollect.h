#ifndef BALLCOLLECT_H
#define BALLCOLLECT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Davey
 */
class BallCollect: public CommandBase {
public:
	BallCollect();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
