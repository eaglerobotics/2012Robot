#include "Eject.h"
#include "../SubSystems/BallCollectionBase.h"

Eject::Eject() {
	// Use requires() here to declare subsystem dependencies
	Requires(ballCollection);
}

// Called just before this Command runs the first time
void Eject::Initialize() {
	// Positive values move rollers backwards.
	ballCollection->moveRollers(0.4);
}

// Called repeatedly when this Command is scheduled to run
void Eject::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool Eject::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Eject::End() {
	ballCollection->moveRollers(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Eject::Interrupted() {
	ballCollection->moveRollers(0.0);
}
