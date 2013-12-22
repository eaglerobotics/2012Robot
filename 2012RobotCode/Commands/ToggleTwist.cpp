#include "ToggleTwist.h"
#include "../Subsystems/DriveTrainBase.h"

ToggleTwist::ToggleTwist() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ToggleTwist::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ToggleTwist::Execute() {
	driveTrain->ToggleTwistDisabled();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleTwist::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleTwist::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleTwist::Interrupted() {
}
