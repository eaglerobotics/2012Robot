#include "FanSim.h"
#include "../Robotmap.h"

FanSim::FanSim() : FanBase() {
	
}
    
void FanSim::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int FanSim::RunFan()
{
	return 0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
