#include "VisionBase.h"
#include "../Robotmap.h"

VisionBase::VisionBase() : Subsystem("VisionBase") {
	
}
    
void VisionBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int VisionBase::particleAnalysis()
{
	return 0;
}

void VisionBase::setTargetParticle(int index)
{
	
}

double VisionBase::getNormalizedXPosition()
{
	return 0;
}

int VisionBase::getXPosition()
{
	return 0;
}

double VisionBase::getNormalizedYPosition()
{
	return 0;
}

int VisionBase::getYPosition()
{
	return 0;
}

float VisionBase::getDistance()
{
	return 0;
}

void VisionBase::setHighRes()
{
	
}

void VisionBase::setLowRes()
{
	
}

int VisionBase::getNumberOfTargets()
{
	return 0;
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
