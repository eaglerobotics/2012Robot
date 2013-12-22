#ifndef TURRETTURNMANUAL_H
#define TURRETTURNMANUAL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author AG132127
 */
class TurretTurnManual: public CommandBase {
public:
	TurretTurnManual();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
