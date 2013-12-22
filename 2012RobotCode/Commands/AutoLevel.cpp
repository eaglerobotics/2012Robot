#include "AutoLevel.h"
#include "../SubSystems/DriveTrainBase.h"

AutoLevel::AutoLevel() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AutoLevel::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AutoLevel::Execute() {
	driveTrain->autoLevel();
	
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLevel::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoLevel::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLevel::Interrupted() {
}
