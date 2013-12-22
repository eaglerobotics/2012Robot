#ifndef TOGGLETWIST_H
#define TOGGLETWIST_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Eagle Robotics
 */
class ToggleTwist: public CommandBase {
public:
	ToggleTwist();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
