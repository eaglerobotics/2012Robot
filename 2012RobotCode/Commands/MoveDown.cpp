#include "MoveDown.h"
#include "../Subsystems/Elevator.h"

MoveDown::MoveDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void MoveDown::Initialize() {
	if(elevator->isBallSlot3())
	{
		targetslot=2;
		waitForClear = elevator->isBallSlot2();
	}
	else if(elevator->isBallSlot2())
	{
		targetslot=1;
		waitForClear = elevator->isBallSlot1();
	}
	else if(elevator->isBallSlot1())
		targetslot=0;
	else targetslot=0;
	
//	timer.Start();
	//lets see of this works
}

// Called repeatedly when this Command is scheduled to run
void MoveDown::Execute() {
	elevator->moveElevator(Elevator::moveDown);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveDown::IsFinished() {
	printf("timer:%f slot1:%i slot2:%i slot3:%i\n",timer.Get(), elevator->isBallSlot1(),elevator->isBallSlot2(),elevator->isBallSlot3());
//	if(timer.Get()<.15)
//		return false;
	if(targetslot==2)
	{
		if(waitForClear)
		{
			waitForClear = elevator->isBallSlot2();
			return false;
		}
		else	
			return elevator->isBallSlot2();
		
	}
	else if(targetslot==1)
	{
		if(waitForClear)
		{
			waitForClear = elevator->isBallSlot1();
			return false;
		}
		else	
			return elevator->isBallSlot1();
		
	}
	else if(targetslot==0)
		return !elevator->isBallSlot1();
	else return false;
}

// Called once after isFinished returns true
void MoveDown::End() {
	elevator->moveElevator(Elevator::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveDown::Interrupted() {
}
