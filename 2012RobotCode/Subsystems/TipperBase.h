#ifndef TIPPERBASE_H
#define TIPPERBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class TipperBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	typedef enum tipperMode {
			extend,
			retract,
			stop,
			holdOut
		};
	
	TipperBase();
	virtual void InitDefaultCommand();
	virtual void TipperBase::MoveTipper(tipperMode mode);
	virtual bool IsExtended();
	virtual bool IsRetracted();
};

#endif
