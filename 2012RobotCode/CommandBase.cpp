#include "CommandBase.h"
#include "RobotMap.h"
#include "Util.h"
#include "Subsystems/DriveTrain.h"
//#include "Commands/Scheduler.h"
#include "Commands/Command.h"

#include "Subsystems/BallCollectionBase.h"
#include "Subsystems/DriveTrainBase.h"
#include "Subsystems/ShooterBase.h"
#include "Subsystems/TurretBase.h"
#include "Subsystems/VisionBase.h"
#include "Subsystems/TipperBase.h"
#include "Subsystems/FanBase.h"
#include "Subsystems/ElevatorBase.h"

#include "Subsystems/BallCollection.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Tipper.h"
#include "Subsystems/Fan.h"
#include "Subsystems/Elevator.h"

#include "Subsystems/BallCollectionSim.h"
#include "Subsystems/DriveTrainSim.h"
#include "Subsystems/ShooterSim.h"
#include "Subsystems/TurretSim.h"
#include "Subsystems/TipperSim.h"
#include "Subsystems/ElevatorSim.h"
#include "Subsystems/FanSim.h"
#include "Subsystems/VisionSim.h"

#include "Subsystems/DriveTrainKitbot.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
BallCollectionBase* CommandBase::ballCollection = NULL;
DriveTrainBase* CommandBase::driveTrain = NULL;
ShooterBase* CommandBase::shooter = NULL;
TurretBase* CommandBase::turret = NULL;
VisionBase* CommandBase::vision = NULL;
TipperBase* CommandBase::tipper = NULL;
FanBase* CommandBase::fan = NULL;
OI* CommandBase::oi	 = NULL;
ElevatorBase* CommandBase::elevator = NULL;


void CommandBase::init() {
	glTraceEnableFlags = 0xffffffff;
	
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

#if defined(COMPETITION)
	printf("Init driveTrain\n");
	driveTrain = new DriveTrain();
	printf("Init ballcollection\n");
	ballCollection = new BallCollection();
	printf("Init shooter\n");
	shooter = new Shooter();
	printf("Init turret\n");
	turret = new Turret();
	printf("Init tipper\n");
	tipper = new Tipper();
	printf("Init fan\n");
	fan = new Fan();
	printf("Init Vision\n");
	vision = new VisionBase();
	printf("Init Elevator\n");
	elevator = new Elevator();
	
#elif defined(SIMULATE) 
	driveTrain = new DriveTrainSim();
	ballCollection = new BallCollectionSim();
	shooter = new Shooter();
	turret = new Turret();
	tipper = new TipperSim();
	fan = new FanSim();
	vision = new Vision();
	elevator = new ElevatorSim();
	
#elif defined(KITBOT)
	driveTrain = new DriveTrain();
	ballCollection = new BallCollectionSim();
	shooter = new ShooterSim();
	turret = new TurretBase();
	tipper = new TipperSim();
	fan = new FanSim();
	vision = new VisionSim();
	elevator = new ElevatorSim();
	
#else 
	driveTrain = new DriveTrain();
	printf("Ball Collection else\n");
	ballCollection = new BallCollection();
	shooter = new Shooter();
	turret = new Turret();
	tipper = new Tipper();
	fan = new Fan();
	vision = new Vision();
	elevator = new Elevator();
	
#endif
	
	printf("Init OI\n");
	oi = new OI();
	
	// send the PID's to the SmartDashboard
//	SmartDashboard::GetInstance()->PutData("TopAxelPID", shooter->getTopAxelPID());
//	SmartDashboard::GetInstance()->PutData("BottomAxelPID", shooter->getBottomAxelPID());
}
