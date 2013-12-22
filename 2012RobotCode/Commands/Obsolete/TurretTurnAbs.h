#ifndef TURRETTURNABS_H
#define TURRETTURNABS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author AG132127
 */
class TurretTurnAbs: public CommandBase {
public:
	TurretTurnAbs();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
