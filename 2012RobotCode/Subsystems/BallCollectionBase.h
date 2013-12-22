#ifndef BALLCOLLECTIONBASE_H
#define BALLCOLLECTIONBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class BallCollectionBase: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	BallCollectionBase();
	virtual void InitDefaultCommand();
	virtual void moveRollers(float speed);
};

#endif
