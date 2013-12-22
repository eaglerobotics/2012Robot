#include "BallCollection.h"
#include "../Robotmap.h"

BallCollection::BallCollection() : BallCollectionBase()
{
	ballCollect2 = new Victor(DEFAULT_ANALOG_MODULE, BALL_COLLECTION_2);
}
    
void BallCollection::InitDefaultCommand()
{

}

void BallCollection::moveRollers(float speed)
{
	// Runs the motors forward in order to collect balls
//	printf("speed:%f\n", speed);
	ballCollect2->Set(speed);
}

