#include "AxelSpeed.h"

AxelSpeed::AxelSpeed()
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void AxelSpeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AxelSpeed::Execute()
{
	// add fShooterSpeed by some constant/varible when setting bottomAxel to 
//	// create spin
//	float fShooterSpeed;
//	shooter->SetTopAxel(fShooterSpeed);
//	shooter->SetBottomAxel();
}

// Make this return true when this Command no longer needs to run execute()
bool AxelSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AxelSpeed::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AxelSpeed::Interrupted()
{
	
}
