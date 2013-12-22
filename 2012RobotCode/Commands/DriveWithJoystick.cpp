#include "DriveWithJoystick.h"
#include "../SubSystems/DriveTrainBase.h"
#include "../util.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {
	driveTrain->zeroGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	Joystick *driverStick = oi->getDriveStick();
	float x = deadband(driverStick->GetAxis(Joystick::kXAxis), 0.2);
	float y = deadband(driverStick->GetAxis(Joystick::kYAxis), 0.2);
	float rotation = deadband(driverStick->GetAxis(Joystick::kZAxis), 0.35);
	
//	printf("x:%f y:%f rotation:%f\n",x,y,rotation);
	driveTrain->mecanumDrive_Cartesian(x,y,rotation);
	SmartDashboard::GetInstance()->PutDouble("Gyro Angle", driveTrain->GetGyroAngle());
}

// Is always being used. Never return true
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
}
