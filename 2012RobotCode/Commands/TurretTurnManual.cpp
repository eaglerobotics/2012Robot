#include "TurretTurnManual.h"
#include "../SubSystems/TurretBase.h"

TurretTurnManual::TurretTurnManual() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(turret);

}

// Called just before this Command runs the first time
void TurretTurnManual::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TurretTurnManual::Execute() {
	
//	turret->setMotor(oi->getOpStickXAxis());
}

// Make this return true when this Command no longer needs to run execute()
bool TurretTurnManual::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurretTurnManual::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurretTurnManual::Interrupted() {
}
