#ifndef VISIONCOMMAND_H
#define VISIONCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jarrett
 */
class VisionCommand: public CommandBase {
public:
	VisionCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
