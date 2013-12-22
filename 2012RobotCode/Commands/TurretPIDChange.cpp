#include "TurretPIDChange.h"
#include "../Subsystems/TurretBase.h"

TurretPIDChange::TurretPIDChange(float dPz, float dIz, float dDz)
{
	dP = dPz;
	dI = dIz;
	dD = dDz;
}

// Called repeatedly when this Command is scheduled to run
void TurretPIDChange::Execute()
{
	turret->DeltaPID(dP, dI, dD);
}
