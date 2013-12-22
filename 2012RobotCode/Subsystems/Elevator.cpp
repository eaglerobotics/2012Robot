#include "Elevator.h"
#include "../Robotmap.h"

Elevator::Elevator() : ElevatorBase() {
	elevatorMtr = new Victor(DEFAULT_DIGITAL_MODULE, CONVEYOR_BELT_VICTOR);
	slot1 = new DigitalInput(DEFAULT_DIGITAL_MODULE, SLOT_1_LIGHT_SENSOR);
	slot2 = new DigitalInput(DEFAULT_DIGITAL_MODULE, SLOT_2_LIGHT_SENSOR);
	slot3 = new DigitalInput(DEFAULT_DIGITAL_MODULE, SLOT_3_LIGHT_SENSOR);
	sweeperArea = new DigitalInput(DEFAULT_DIGITAL_MODULE, SWEEPER_LIGHT_SENSOR);
}
    
void Elevator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Elevator::moveElevator(Elevator::elevatorMode mode)
{
//	printf("Elevator moveElevator:%i\n", mode);
	switch (mode)
	{
	case moveUp:
		elevatorMtr->Set(0.4);
		break;
	case moveDown:
		elevatorMtr->Set(-0.4);
		break;
	case stop:
		elevatorMtr->Set(0.0);
	}
}

bool Elevator::isBallSlot1()
{
	return slot1->Get();
}

bool Elevator::isBallSlot2()
{
	return slot2->Get();
}

bool Elevator::isBallSlot3()
{
	return slot3->Get();
}

bool Elevator::isBallSweeperArea()
{
	return sweeperArea->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
