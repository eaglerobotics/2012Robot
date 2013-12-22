#include "ShooterBase.h"
#include "../Robotmap.h"

ShooterBase::ShooterBase() : Subsystem("ShooterBase") {
	
}
    
void ShooterBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ShooterBase::SetRange(float distance)
{	

}

void ShooterBase::TopAxelPID()
{

}

void ShooterBase::BottomAxelPID()
{

}

void ShooterBase::SetTopAxel(float fShooterSpeed)
{
	
}

void ShooterBase::SetBottomAxel(float fShooterSpeed)
{
	
}

void ShooterBase::MoveConveyor()
{
	
}

void ShooterBase::SetPowerAll(float power)
{
	
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
