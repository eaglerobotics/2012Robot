#ifndef BALL_COLLECTION_H
#define BALL_COLLECTION_H
#include "BallCollectionBase.h"
#include "WPILib.h"

/**
 *
 *
 * @author David
 */
class BallCollection: public BallCollectionBase {
private:
	// Create variable for the BallCollection Victor
	Victor *ballCollect2;

public:
	BallCollection();
	virtual void InitDefaultCommand();
	virtual void moveRollers(float speed);
};

#endif
