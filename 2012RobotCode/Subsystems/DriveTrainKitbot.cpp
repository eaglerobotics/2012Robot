#include "DriveTrainKitbot.h"
#include "../Robotmap.h"

DriveTrainKitbot::DriveTrainKitbot() : DriveTrainBase()
{	
	// NOTE: This is modified from the original to fit the kitbot
	drive = new RobotDrive(2, 1, 3, 4);
	
	gyro = new Gyro(DEFAULT_ANALOG_MODULE, DRIVETRAIN_GYRO_CHANNEL);
	
//	prevOpButtons = new bool[12];
//	pidAutoLevel = new SendablePIDController(0.0, 0.0, 0.1, gyro, pidPower);
	gyroTrim = 0;
}
    
void DriveTrainKitbot::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrainKitbot::mecanumDrive_Polar(float direction, float power)
{
	drive->MecanumDrive_Polar(power, direction, 0);
}

void DriveTrainKitbot::mecanumDrive_Cartesian(float x, float y, float rotation)
{
	// Get the angle from the Gyro
	float angle = getGyroAngle();
	
	drive->MecanumDrive_Cartesian(x, y, rotation, angle);
}

void DriveTrainKitbot::driveWithJoystick(Joystick *joystick)
{
	// Get the Axes from the joystick
	float xPower = joystick->GetAxis(Joystick::kXAxis);
	float yPower = joystick->GetAxis(Joystick::kYAxis);
	float twistPower = joystick->GetAxis(Joystick::kTwistAxis); 
	
//	// edge detection on all 4 buttons
//	bool fineLeft = joystick->GetRawButton(FINE_LEFT_BUTTON)&&!prevOpButtons[FINE_LEFT_BUTTON-1];
//	bool fineRight = joystick->GetRawButton(FINE_RIGHT_BUTTON)&&!prevOpButtons[FINE_RIGHT_BUTTON-1];
//	bool coarseLeft = joystick->GetRawButton(COARSE_LEFT_BUTTON)&&!prevOpButtons[COARSE_LEFT_BUTTON-1];
//	bool coarseRight = joystick->GetRawButton(COARSE_RIGHT_BUTTON)&&!prevOpButtons[COARSE_RIGHT_BUTTON-1];
//	
//	// Adjust the gyroTrim variable
//	gyroTrim += fineLeft*-2 + fineRight*-2 + coarseLeft*-10 + coarseRight*-10;

	mecanumDrive_Cartesian(xPower, yPower, twistPower);
	
	// Store the current button states as the previous
	// "for" thingy
//	for (int i = 0; i < 12; i++)
//	{
//		prevOpButtons[i] = joystick->GetRawButton(i-1);
//	}
}

void DriveTrainKitbot::autoLevel()
{
//	// Get the angle from the gyro.
//	//float angle = getGyroAngle();
//	// Set the PID info.
//	pidAutoLevel->SetPID(0.0, 0.0, 0.1);
//	pidAutoLevel->SetOutputRange(0, 1);
	
}


float DriveTrainKitbot::getGyroAngle()
{
	// At the moment we will just straight get the angle
	// However, we may add compensation for drift later
	return gyro->GetAngle()+gyroTrim;
}

//void *DriveTrainKitbot::pidPower()
//{
//	return NULL;
//}
