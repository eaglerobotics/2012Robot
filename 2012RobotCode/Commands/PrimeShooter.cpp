#include "PrimeShooter.h"
#include "../Subsystems/Elevator.h"

PrimeShooter::PrimeShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(elevator);
	SetTimeout(2);
}

// Called just before this Command runs the first time
void PrimeShooter::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void PrimeShooter::Execute() {
//	printf("PrimeShooter Execute\n");
	elevator->moveElevator(Elevator::moveUp);
}

// Make this return true when this Command no longer needs to run execute()
bool PrimeShooter::IsFinished() {
	//when slot 3
//	bool x=elevator->isBallSlot3();
//	printf("isSlot3?:%i\n", x);
	return elevator->isBallSlot3()||IsTimedOut();
//	return false;
}

// Called once after isFinished returns true
void PrimeShooter::End() {
	elevator->moveElevator(Elevator::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrimeShooter::Interrupted() {
	elevator->moveElevator(Elevator::stop);
}
