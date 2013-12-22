#include "TurretTurnAuto.h"
#include "../SubSystems/TurretBase.h"
TurretTurnAuto::TurretTurnAuto() {

}

// Called just before this Command runs the first time
void TurretTurnAuto::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TurretTurnAuto::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool TurretTurnAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurretTurnAuto::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurretTurnAuto::Interrupted() {
}
