#ifndef TRIMGYRO_H
#define TRIMGYRO_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Scott
 */
class TrimGyro: public CommandBase {
public:
	typedef enum trimMode {fineLeft, fineRight, coarseLeft, coarseRight, zero};
	
private:
	bool finished;
	trimMode mode;
	
public:
	
	TrimGyro(trimMode mode);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
