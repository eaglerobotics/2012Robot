#ifndef RUNTHEFAN_H
#define RUNTHEFAN_H

#include "../CommandBase.h"
/**
 *
 *
 * @author Jarrett
 */
class RunTheFan: public CommandBase {
public:
	RunTheFan();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
};

#endif
