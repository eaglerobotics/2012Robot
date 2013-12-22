#include "SetSpeed.h"

SetSpeed::SetSpeed() {
	Requires(ballCollection);
}

// Called just before this Command runs the first time
void SetSpeed::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void SetSpeed::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool SetSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetSpeed::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetSpeed::Interrupted() {
}
