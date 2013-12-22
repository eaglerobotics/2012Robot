#include "BallCollect.h"
#include "../SubSystems/BallCollection.h"

BallCollect::BallCollect() {
	// Use requires() here to declare subsystem dependencies
	Requires(ballCollection);
}

// Called just before this Command runs the first time
void BallCollect::Initialize() {
//	printf("BallCollect Initialized\n");
}

// Called repeatedly when this Command is scheduled to run
void BallCollect::Execute() {
//	printf("BallCollect Execute\n");
	// Negative values move motors forward.
	ballCollection->moveRollers(-0.4);
}

// Make this return true when this Command no longer needs to run execute()
bool BallCollect::IsFinished() {
	// Review: Is this really what we want?
//	return !oi->getButtonStick()->GetRawButton(5);
	return false;
}

// Called once after isFinished returns true
void BallCollect::End() {
	ballCollection->moveRollers(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallCollect::Interrupted() {
	ballCollection->moveRollers(0.0);
}
