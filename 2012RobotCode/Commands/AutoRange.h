#ifndef AUTORANGE_H
#define AUTORANGE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jarrett
 */
class AutoRange: public CommandBase {
public:
	AutoRange();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
