#include "Fan.h"
#include "../Robotmap.h"

Fan::Fan() : FanBase()
{
	fan = new Relay(DEFAULT_DIGITAL_MODULE,FAN);
}
    
void Fan::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int Fan::RunFan()
{
	fan->Set(Relay::kForward);
	return 1;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
