#include "WPILib.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/RunTheFan.h"
#include "Commands/AutoCollect.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/TurretBase.h"
#include "CommandBase.h"

class RobotMain : public IterativeRobot {
private:
	
	Command *driveWithJoystick;
//	Command *runTheFan;
//	Command *autoBallCollect;
	
	virtual void LimitSwitchCheck()
	{
		if (CommandBase::turret->isLlimit() && CommandBase::turret->getMotor() < 0 ){
			printf("L limit switch hit\n");
			CommandBase::turret->setMotor(0);
		}
		else if (CommandBase::turret->isRlimit() && CommandBase::turret->getMotor() > 0 ){
			printf("R limit switch hit\n");
			CommandBase::turret->setMotor(0);
		}
	}
	
	virtual void RobotInit() {
		CommandBase::init();
		driveWithJoystick = new DriveWithJoystick();
		RunTheFan *runTheFan = new RunTheFan();
		runTheFan->Start();
	}
	
	virtual void AutonomousInit() {
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
		LimitSwitchCheck();
	}
	
	virtual void TeleopInit() {
		driveWithJoystick->Start();
//		autoBallCollect->Start();
//		runTheFan->Start();
//		autoAim->Start();
	}
	
	virtual void TeleopPeriodic() {
//		printf("top=%.2f (PID=%.2f, set=%.2f), bottom=%.2f (PID=%.2f, set=%.2f)\n", 
//				(float)((Shooter *)CommandBase::shooter)->topAxelEncoder->PIDGet(),
//				(float)((Shooter *)CommandBase::shooter)->pidTopAxel->Get(),
//				(float)((Shooter *)CommandBase::shooter)->pidTopAxel->GetSetpoint(),
//				(float)((Shooter *)CommandBase::shooter)->bottomAxelEncoder->PIDGet(),
//				(float)((Shooter *)CommandBase::shooter)->pidBottomAxel->Get(),
//				(float)((Shooter *)CommandBase::shooter)->pidBottomAxel->GetSetpoint());
		Scheduler::GetInstance()->Run();
		LimitSwitchCheck();		// async limit switch checking
	}
	
	virtual void DisabledInit() {
//		Preferences::GetInstance()->Save();
	}
};

START_ROBOT_CLASS(RobotMain);

