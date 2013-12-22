#ifndef TURRETTURNAUTO_H
#define TURRETTURNAUTO_H

#include "../CommandBase.h"

/**
 *
 *
 * @author AG132127
 */
class TurretTurnAuto: public CommandBase {
public:
	TurretTurnAuto();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
