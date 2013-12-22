#include "VisionCommand.h"
#include "../SubSystems/VisionBase.h"


VisionCommand::VisionCommand()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(vision);
}

// Called just before this Command runs the first time
void VisionCommand::Initialize()
{
	
}

// Called repeatedly when this Command is scheduled to run
void VisionCommand::Execute()
{
	// the vision command will just compute the data recieved from the camera
	// and complies it to range, angle, and other important variables
}

// Make this return true when this Command no longer needs to run execute()
bool VisionCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void VisionCommand::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionCommand::Interrupted()
{
	
}
