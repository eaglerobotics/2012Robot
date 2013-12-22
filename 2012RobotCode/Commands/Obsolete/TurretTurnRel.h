#ifndef TURRETTURNREL_H
#define TURRETTURNREL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author AG132127
 */
class TurretTurnRel: public CommandBase {
public:
	TurretTurnRel();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
