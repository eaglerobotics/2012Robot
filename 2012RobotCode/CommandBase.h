#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

//#include "Commands/Command.h"
//
//#include "Subsystems/BallCollectionBase.h"
//#include "Subsystems/DriveTrainBase.h"
//#include "Subsystems/ShooterBase.h"
//#include "Subsystems/TurretBase.h"
//#include "Subsystems/VisionBase.h"
//#include "Subsystems/TipperBase.h"
//#include "Subsystems/FanBase.h"
//#include "Subsystems/ElevatorBase.h"
//
//#include "Subsystems/BallCollection.h"
//#include "Subsystems/DriveTrain.h"
//#include "Subsystems/Shooter.h"
//#include "Subsystems/Turret.h"
//#include "Subsystems/Vision.h"
//#include "Subsystems/Tipper.h"
//#include "Subsystems/Fan.h"
//#include "Subsystems/Elevator.h"
//
//#include "Subsystems/BallCollectionSim.h"
//#include "Subsystems/DriveTrainSim.h"
//#include "Subsystems/ShooterSim.h"
//#include "Subsystems/TurretSim.h"
//#include "Subsystems/TipperSim.h"
//#include "Subsystems/ElevatorSim.h"
//#include "Subsystems/FanSim.h"
//
//#include "Subsystems/DriveTrainKitbot.h"


class BallCollectionBase;
class DriveTrainBase;
class ShooterBase;
class TurretBase;
class VisionBase;
class TipperBase;
class FanBase;
class ElevatorBase;

class BallCollection;
class DriveTrain;
class Shooter;
class Turret;
class Vision;
class Tipper;
class Fan;
class Elevator;

class BallCollectionSim;
class DriveTrainSim;
class ShooterSim;
class TurretSim;
class TipperSim;
class ElevatorSim;
class FanSim;

class DriveTrainKitbot;

#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static BallCollectionBase *ballCollection;
	static DriveTrainBase *driveTrain;
	static ShooterBase *shooter;
	static TurretBase *turret;
	static VisionBase *vision;
	static TipperBase *tipper;
	static ElevatorBase *elevator;
	static FanBase *fan;
	
	static OI *oi;
};

#endif
