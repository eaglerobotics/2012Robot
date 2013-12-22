#include "ManualAim.h"
#include "../SubSystems/TurretBase.h"
#include "../Util.h"

ManualAim::ManualAim() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires (turret);
}

// Called just before this Command runs the first time
void ManualAim::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ManualAim::Execute() {
	float xAxis = oi->getOpStickXAxis();
	float power = deadband(xAxis, 0.3, 0.05, 1); 
	turret->setMotor(power);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualAim::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ManualAim::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualAim::Interrupted() {
}
