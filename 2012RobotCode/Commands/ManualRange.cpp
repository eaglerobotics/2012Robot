#include "ManualRange.h"
#include "../SubSystems/ShooterBase.h"

ManualRange::ManualRange() 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void ManualRange::Initialize() 
{
	printf("ManualRange init\n");
}

// Called repeatedly when this Command is scheduled to run
void ManualRange::Execute() 
{
	float yAxis = oi->getSliderPower();
//	float upPower = 1-((yAxis +1 )/2);
//	printf("upPower: %.2f\n", upPower);
	// shooter->SetRange is not set up to take the parameter "upPower" so the function
	// will not work properly
	printf("range: %.2f\n", yAxis);
	shooter->SetRange(yAxis*10);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualRange::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void ManualRange::End() 
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualRange::Interrupted() 
{
	
}
