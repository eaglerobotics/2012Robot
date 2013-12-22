#include "Tipper.h"
#include "../Robotmap.h"

Tipper::Tipper() : TipperBase() 
{
	tipperMtr = new Victor(DEFAULT_ANALOG_MODULE, BRIDGE_CONTROL_MOTOR);
	limitSwitchExtended = new DigitalInput(DEFAULT_DIGITAL_MODULE, TIPPER_EXTEND_LIMIT);
	limitSwitchRetracted = new DigitalInput(DEFAULT_DIGITAL_MODULE, TIPPER_RETRACT_LIMIT);
}
    
void Tipper::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}

void Tipper::MoveTipper(tipperMode mode)
{
	switch (mode)
	{
	case extend:
		tipperMtr->Set(0.20);
		break;
	case retract:
		tipperMtr->Set(-0.10);
		break;
	case stop:
		tipperMtr->Set(0);
		break;
	case holdOut:
		tipperMtr->Set(.2);
		break;
	}
}

bool Tipper::IsExtended()
{
	return limitSwitchExtended->Get();
}

bool Tipper::IsRetracted()
{
	return limitSwitchRetracted->Get();
}
