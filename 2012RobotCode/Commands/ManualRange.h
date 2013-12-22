#ifndef MANUALRANGE_H
#define MANUALRANGE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ag291863
 */
class ManualRange: public CommandBase {
public:
	ManualRange();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
