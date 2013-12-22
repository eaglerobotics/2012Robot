#include "BallCollectionBase.h"
#include "../Robotmap.h"

BallCollectionBase::BallCollectionBase() : Subsystem("BallCollectionBase") {
	
}
    
void BallCollectionBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BallCollectionBase::moveRollers(float speed)
{
	printf("Base moveRollers\n");
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
