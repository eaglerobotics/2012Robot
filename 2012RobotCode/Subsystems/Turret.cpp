#include "Turret.h"
#include "../Util.h"
#include "../Robotmap.h"
#include "../Commands/ManualAim.h"

Turret::Turret() : TurretBase() {
	turretMotor = new Victor( DEFAULT_ANALOG_MODULE, TURRET_VICTOR_ID);
	turretSwitchL = new DigitalInput(DEFAULT_DIGITAL_MODULE, TURRET_LEFT_LIMIT);
	turretSwitchR = new DigitalInput(DEFAULT_DIGITAL_MODULE, TURRET_RIGHT_LIMIT);
	
	GetPIDController()->SetPID(0.05,0.005,0);
	SmartDashboard::GetInstance()->PutData("TurretPID", (SendablePIDController *)GetPIDController());
}

void Turret::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ManualAim());
}

void Turret::setMotor(float xAxis){
	if(xAxis < 0 && isLlimit())
		xAxis = 0;
	else if(xAxis > 0 && isRlimit())
		xAxis = 0;

	xAxis = max(-0.08f, min(xAxis, 0.08f));
//	TracePrint(TRACE_TURRET, "setMotor=%.2f\n", xAxis);

	if(xAxis > 0)
		xAxis += 0.08;
	else if(xAxis < 0)
		xAxis -= 0.08;
	
	turretMotor->Set(xAxis);
}

bool Turret::isLlimit(){
	return turretSwitchL->Get();
}

bool Turret::isRlimit(){
	return turretSwitchR->Get();	
}

float Turret::getMotor(){
	return turretMotor->Get();
}

void Turret::UsePIDOutput(double output) 
{
	setMotor(-output);
}

void Turret::DeltaPID(float dP, float dI, float dD)
{
	GetPIDController()->SetPID(
			GetPIDController()->GetP()+dP, 
			GetPIDController()->GetI()+dI, 
			GetPIDController()->GetD()+dD);
	
	TracePrint(TRACE_TURRET, "New P=%.4f, I=%.4f, D=%.4f\n",
			GetPIDController()->GetP(), 
			GetPIDController()->GetI(), 
			GetPIDController()->GetD());
}
