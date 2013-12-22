#ifndef MANUALAIM_H
#define MANUALAIM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ag291863
 */
class ManualAim: public CommandBase {
public:
	ManualAim();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
