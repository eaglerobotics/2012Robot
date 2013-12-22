#include "MoveElevator.h"
#include "../Subsystems/Elevator.h"
//MoveElevator - Needs to prime the ball, move the elevator up, and
//move the elevator down. 


MoveElevator::MoveElevator(Elevator::elevatorMode mode) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	//Requires();
	this->mode = mode;
	Requires(elevator);
}

// Called just before this Command runs the first time
void MoveElevator::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() 
{
	if (!elevator->isBallSlot3())
	{
		printf("Check Sweeper:%i\n", elevator->isBallSweeperArea());
		if (elevator->isBallSweeperArea())
		{
			elevator->moveElevator(mode);
			waitForClear = elevator->isBallSlot1();
		}
		if (elevator->isBallSlot1()&&!waitForClear)
			elevator->moveElevator(Elevator::stop);
		if (waitForClear&&!elevator->isBallSlot1())
			waitForClear = false;
	}
	else
		elevator->moveElevator(Elevator::stop);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished() {
	//when sweeper not on
	return false;
//	return !oi->getButtonStick()->GetRawButton(5);
}

// Called once after isFinished returns true
void MoveElevator::End() {
	elevator->moveElevator(Elevator::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted() {
	elevator->moveElevator(Elevator::stop);
}
