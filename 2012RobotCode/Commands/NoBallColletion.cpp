#include "NoBallColletion.h"
#include "../SubSystems/BallCollectionBase.h"

NoBallColletion::NoBallColletion() {
	// Use requires() here to declare subsystem dependencies
	Requires(ballCollection);
}

// Called just before this Command runs the first time
void NoBallColletion::Initialize() {
	ballCollection->moveRollers(0.0);
}

// Called repeatedly when this Command is scheduled to run
void NoBallColletion::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool NoBallColletion::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void NoBallColletion::End() {
	ballCollection->moveRollers(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NoBallColletion::Interrupted() {
	ballCollection->moveRollers(0.0);
}
