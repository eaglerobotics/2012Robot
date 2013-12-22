#include "MoveTipper.h"
#include "../Subsystems/Tipper.h"

MoveTipper::MoveTipper(Tipper::tipperMode mode) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	
	this->mode = mode;
	Requires(tipper);
}

// Called just before this Command runs the first time
void MoveTipper::Initialize() 
{
//	SetTimeout(0.1);
}

// Called repeatedly when this Command is scheduled to run
void MoveTipper::Execute() 
{
	tipper->MoveTipper(mode);
	
	if (mode == Tipper::extend && tipper->IsExtended())
		tipper->MoveTipper(Tipper::stop);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveTipper::IsFinished() 
{
	SmartDashboard::GetInstance()->PutBoolean("Extended",tipper->IsExtended());
	SmartDashboard::GetInstance()->PutBoolean("Retracted",tipper->IsRetracted());
	switch (mode)
	{
	case Tipper::extend:
		return false;
	case Tipper::retract:
		return tipper->IsRetracted();
	case Tipper::stop:
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void MoveTipper::End() 
{
	tipper->MoveTipper(Tipper::stop);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveTipper::Interrupted() 
{
	tipper->MoveTipper(Tipper::stop);
}
