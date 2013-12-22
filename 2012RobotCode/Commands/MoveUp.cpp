#include "MoveUp.h"
#include "../Subsystems/Elevator.h"

MoveUp::MoveUp(bool SafetyEnabled) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(elevator);
	SetTimeout(1.5);
	safety = SafetyEnabled;
}

// Called just before this Command runs the first time
void MoveUp::Initialize() {
	if(elevator->isBallSlot3()&&safety)
		targetslot=0;
	else if(elevator->isBallSlot2()||(elevator->isBallSlot3()&&!safety))
	{
		targetslot=3;
		waitForClear = elevator->isBallSlot3();
	}
	else if(elevator->isBallSlot1())
	{
		targetslot=2;
		waitForClear = elevator->isBallSlot2();
	}
	else
	{
		targetslot=1;
		waitForClear = elevator->isBallSlot1();
	}
	
}

// Called repeatedly when this Command is scheduled to run
void MoveUp::Execute() {
	elevator->moveElevator(Elevator::moveUp);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUp::IsFinished() {
	
	if (IsTimedOut())
		return true;
	
	//the logic on my whiteboard will go here.
//	printf("timer:%f slot1:%i slot2:%i slot3:%i\n",timer.Get(), elevator->isBallSlot1(),elevator->isBallSlot2(),elevator->isBallSlot3());
	if(targetslot==3)
	{
		if (waitForClear)
		{
			waitForClear = elevator->isBallSlot3();
			return false;
		}
		else
			return elevator->isBallSlot3();
	}
	else if(targetslot==2)
	{
		if (waitForClear)
		{
			waitForClear = elevator->isBallSlot2();
			return false;
		}
		else
			return elevator->isBallSlot2();
	}
	else if(targetslot==1)
	{
		if (waitForClear)
		{
			waitForClear = elevator->isBallSlot1();
			return false;
		}
		else
			return elevator->isBallSlot1();
	}
	else if(targetslot==0)
		return true;
	else return IsTimedOut();
}

// Called once after isFinished returns true
void MoveUp::End() {
	elevator->moveElevator(Elevator::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUp::Interrupted() {
	elevator->moveElevator(Elevator::stop);
}
