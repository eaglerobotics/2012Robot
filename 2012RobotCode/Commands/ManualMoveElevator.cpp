#include "ManualMoveElevator.h"
#include "../Subsystems/Elevator.h"
#include "../OI.h"

ManualMoveElevator::ManualMoveElevator(Elevator::elevatorMode mode) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	
	this->mode = mode;
	Requires(elevator);
}

// Called just before this Command runs the first time
void ManualMoveElevator::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ManualMoveElevator::Execute() {
	elevator->moveElevator(mode);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualMoveElevator::IsFinished() {
//	return !oi->getOpStick()->GetRawButton(6) && !oi->getOpStick()->GetRawButton(7);
	return false;
}

// Called once after isFinished returns true
void ManualMoveElevator::End() {
	elevator->moveElevator(Elevator::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualMoveElevator::Interrupted() {
	elevator->moveElevator(Elevator::stop);
}
