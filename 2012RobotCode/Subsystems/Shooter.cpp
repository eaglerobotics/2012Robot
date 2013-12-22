#include "Shooter.h"
#include "../Robotmap.h"
#include "../OI.h"
#include "../Commands/ManualRange.h"

Shooter::Shooter() : ShooterBase()
{
	topAxel = new Victor(TOP_AXEL_VICTOR);
	bottomAxel = new Victor(BOTTOM_AXEL_VICTOR);

	topAxelEncoder = new Encoder(TOP_AXEL_ENCODER_A,TOP_AXEL_ENCODER_B, false, Encoder::k4X);
	topAxelEncoder->SetPIDSourceParameter(Encoder::kRate);
	topAxelEncoder->SetDistancePerPulse(0.00581759);		// feet per count
	topAxelEncoder->Start();

	bottomAxelEncoder = new Encoder(BOTTOM_AXEL_ENCODER_A,BOTTOM_AXEL_ENCODER_B, false, Encoder::k4X);
	bottomAxelEncoder->SetPIDSourceParameter(Encoder::kRate);
	bottomAxelEncoder->SetDistancePerPulse(0.00581759);		// feet per count
	bottomAxelEncoder->Start();
	
	pidTopAxel = new SendablePIDController(0.01, 0.001, 0.0, topAxelEncoder, topAxel);
	pidBottomAxel = new SendablePIDController(0.01, 0.001, 0.0, bottomAxelEncoder, bottomAxel);

	pidTopAxel->SetOutputRange(-0.5,0.5);
	pidTopAxel->SetInputRange(0,100);
	pidTopAxel->SetSetpoint(0);
	pidTopAxel->Reset();
	pidTopAxel->Enable();
	
	pidBottomAxel->SetOutputRange(-0.5,0.5);
	pidBottomAxel->SetInputRange(-100, 0);
	pidBottomAxel->SetSetpoint(0);
	pidBottomAxel->Reset();
	pidBottomAxel->Enable();
}
    
void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ManualRange());
}

void Shooter::SetRange(float distance)
{	
//	printf("Setting range:%f topAxel:%f topEncoder:%i\n",distance,topAxel->Get(),topAxelEncoder->Get());
	float speed, m = 0.6981, b = 16.5255;
	// fps_to_rpm is a ratio of 1 rpm / 0.034907 fps
//	float fps_to_rpm = 0.034907, max_rpm = 2500.0;
	
	// use the distance (feet) to calculate the rpm of the top and bottom axel to
	// achieve the proper velocity to make a basket
	speed = ((m * distance) + b);// / fps_to_rpm;
	if(speed > 1)
	{
		printf("Shooter speed: %.2f\n", speed);
		SetTopAxel (speed);
		SetBottomAxel (-speed);
		pidTopAxel->Enable();
		pidBottomAxel->Enable();
	}
	else
	{
		printf("Shooter disabled\n");
		pidTopAxel->Disable();
		pidBottomAxel->Disable();
		topAxel->Set(0);
		bottomAxel->Set(0);
	}
}

void Shooter::TopAxelPID()
{
//	DistancePerPulse is in inches
	topAxelEncoder->SetDistancePerPulse(0.06981);
}

void Shooter::BottomAxelPID()
{
	//	DistancePerPulse is inches
	bottomAxelEncoder->SetDistancePerPulse(0.06981);	
}

void Shooter::SetTopAxel(float fShooterSpeed)
{
	pidTopAxel->SetSetpoint(fShooterSpeed);
}

void Shooter::SetBottomAxel(float fShooterSpeed)
{
	pidBottomAxel->SetSetpoint(fShooterSpeed);
}

void Shooter::SetPowerAll(float power)
{
	printf("topEncoder:%i\n",topAxelEncoder->Get());
	topAxel->Set(power);
	bottomAxel->Set(power);
}

//void Shooter::MoveConveyor()
//{
//	conveyorBelt->Set(0.5);
//}
