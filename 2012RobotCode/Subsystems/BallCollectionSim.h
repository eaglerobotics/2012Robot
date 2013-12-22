#ifndef BALL_COLLECTIONSIM_H
#define BALL_COLLECTIONSIM_H
#include "Commands/Subsystem.h"
#include "BallCollectionBase.h"
#include "WPILib.h"

/**
 *
 *
 * @author Jarrett
 */
class BallCollectionSim: public BallCollectionBase
{
private:
	
	
public:
	BallCollectionSim();
	void InitDefaultCommand();
	void moveRollers(float speed);
};

#endif
