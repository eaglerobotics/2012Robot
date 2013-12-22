#include "TipperBase.h"
#include "../Robotmap.h"

TipperBase::TipperBase() : Subsystem("TipperBase") {
	
}
    
void TipperBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void TipperBase::MoveTipper(tipperMode mode)
{
	
}

bool TipperBase::IsExtended()
{
	return false;
}

bool TipperBase::IsRetracted()
{
	return false;
}
