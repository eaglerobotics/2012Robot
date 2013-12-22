#include "TrimGyro.h"
#include "../Subsystems/DriveTrainBase.h"

TrimGyro::TrimGyro(trimMode mode) {
	// Use requires() here to declare subsystem dependencies
	this->mode = mode;
}

// Called just before this Command runs the first time
void TrimGyro::Initialize() {
	finished = false;
}

// Called repeatedly when this Command is scheduled to run
void TrimGyro::Execute() {
	switch(mode)
	{
	case fineLeft:
		driveTrain->fineTrimLeft();
//		printf("fineLeft\n");
		break;
	case coarseLeft:
		driveTrain->coarseTrimLeft();
//		printf("coarseLeft\n");
		break;
	case fineRight:
		driveTrain->fineTrimRight();
//		printf("fineRight\n");
		break;
	case coarseRight:
		driveTrain->coarseTrimRight();
//		printf("coarseRight\n");
		break;
	case zero:
		driveTrain->zeroGyro();
//		printf("zero\n");
		break;
	}
	
	finished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool TrimGyro::IsFinished() {
	return finished;
}

// Called once after isFinished returns true
void TrimGyro::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrimGyro::Interrupted() {
}
