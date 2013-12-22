#include "DriveTrain.h"

DriveTrain::DriveTrain() : DriveTrainBase()
{
#if defined(COMPETITION)
	
//	printf("Init the CAN\n");
	
	frontLeft = new CANJaguar(FRONT_LEFT_CAN_ID);
	backLeft = new CANJaguar(BACK_LEFT_CAN_ID);
	frontRight = new CANJaguar(FRONT_RIGHT_CAN_ID);
	backRight = new CANJaguar(BACK_RIGHT_CAN_ID);
	
//	printf("init robotDrive\n");
	drive = new RobotDrive(frontLeft,backLeft,frontRight,backRight);
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor,true);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor,true);

#elif defined(MURPHY)
	
//	printf("Init the CAN\n");
	
	frontLeft = new CANJaguar(5);
	backLeft = new CANJaguar(6);
	frontRight = new CANJaguar(4);
	backRight = new CANJaguar(2);
	
//	printf("init robotDrive\n");
	drive = new RobotDrive(frontLeft,backLeft,frontRight,backRight);
	
#elif defined(KITBOT)	
//	 NOTE: This is modified from the original to fit the kitbot
	drive = new RobotDrive(2, 1, 3, 4);
	
	
#endif	

	drive->SetSafetyEnabled(false);
	
//	printf("Init gyro\n");
	gyro = new GyroWithTrim(DEFAULT_ANALOG_MODULE, DRIVETRAIN_GYRO_CHANNEL);
//	gyro = new Gyro(DEFAULT_ANALOG_MODULE, DRIVETRAIN_GYRO_CHANNEL);
	
//	printf("inti pidout\n");
	pidOut = new manualPIDOutput();
	
//	prefs = Preferences::GetInstance();
//	float p = prefs->GetFloat("gyro_pid_p",0.005);
//	float i = prefs->GetFloat("gyro_pid_i");
//	float d = prefs->GetFloat("gyro_pid_d");
	gyroHeadingPID = new SendablePIDController(0.0075,0,0,gyro,pidOut);
	// Review: Verify lastest code
//	printf("smartdashboard stuffs\n");
	SmartDashboard::GetInstance()->PutData("gyroHeadingPID", gyroHeadingPID);
	gyroHeadingPID->SetSetpoint(0);
	gyroHeadingPID->SetContinuous(true);
	gyroHeadingPID->SetOutputRange(-1.0, 1.0);
	gyroHeadingPID->Enable();
	
	// Initialize some variables that will be used later
	desiredHeading = gyro->GetAngle();
	
	timer.Start();
	
	disableTwist = false;
	
//	printf("done init\n");
}
    
void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::mecanumDrive_Polar(float direction, float power)
{
	drive->MecanumDrive_Polar(power, direction, 0);
}

void DriveTrain::mecanumDrive_Cartesian(float x, float y, float rotation)
{
	rotation *= !disableTwist;
#if defined(KITBOT)
	x /= 3;
	y /= 3;
	rotation /= 3;
#endif	
	
	// Get the angle from the Gyro
	float angle = gyro->GetAngle();
//	printf("rotation:%f timer:%f\n",rotation, timer.Get());
//	printf("x:%f y:%f rot:%f timer:%f\n",x,y,rotation,timer.Get());
	if (rotation!=0)
	{
		drive->MecanumDrive_Cartesian(x,y,rotation,angle);
		desiredHeading = angle;
		timer.Reset();
		return;
	}
	else if (rotation==0&&timer.Get()<timeout)
	{
		drive->MecanumDrive_Cartesian(x,y,rotation,angle);
		desiredHeading = angle;
		return;
	}
	else if (rotation==0&&timer.Get()>timeout)
	{
		drive->MecanumDrive_Cartesian(x,y,headingHold(),angle);
		return;
	}
	else
	{
		drive->MecanumDrive_Cartesian(x,y,rotation,angle);
		desiredHeading = angle;
	}
	
}

float DriveTrain::headingHold()
{
		gyroHeadingPID->SetSetpoint(desiredHeading);
//		printf("gyroAngle:%f pidOut:%f gyroTrim:%f\n",gyro->GetAngle(), pidOut->getValue(), gyro->GetTrim());
		
//		prefs->PutFloat("gyro_pid_p",gyroHeadingPID->GetP());
//		prefs->PutFloat("gyro_pid_i",gyroHeadingPID->GetI());
//		prefs->PutFloat("gyro_pid_d",gyroHeadingPID->GetD());
		return pidOut->getValue();
}

void DriveTrain::autoLevel()
{
	
}

void DriveTrain::fineTrimLeft()
{
	gyro->SetTrim(gyro->GetTrim()-2);
}

void DriveTrain::coarseTrimLeft()
{
	gyro->SetTrim(gyro->GetTrim()-10);
}

void DriveTrain::fineTrimRight()
{
	gyro->SetTrim(gyro->GetTrim()+2);
}

void DriveTrain::coarseTrimRight()
{
	gyro->SetTrim(gyro->GetTrim()+10);
}

void DriveTrain::zeroGyro()
{
	gyro->ZeroGyro();
	desiredHeading = gyro->GetAngle();
}

void DriveTrain::ToggleTwistDisabled()
{
	disableTwist = !disableTwist;
}

float DriveTrain::GetGyroAngle()
{
	return gyro->GetAngle();
}
