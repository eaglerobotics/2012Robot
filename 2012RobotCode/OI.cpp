//IF ANY COMMAND NAMES CHANGES TELL ME (SHERIDAN)!!!
#include "OI.h"
#include "Robotmap.h"
#include "Commands/TrimGyro.h"
#include "Commands/MoveTipper.h"
#include "Commands/Fire.h"
#include "Commands/MoveElevator.h"
#include "Commands/AutoAim.h"
#include "Commands/ManualAim.h"
#include "Commands/AutoRange.h"
#include "Commands/ManualRange.h"
#include "Commands/BallCollect.h"
#include "Commands/NoBallColletion.h"
#include "Commands/Eject.h"
#include "Commands/AutoLevel.h"
#include "Commands/ManualMoveElevator.h"
#include "Commands/PrimeShooter.h"
#include "Commands/MoveUp.h"
#include "Commands/MoveDown.h"
#include "Commands/AutoCollect.h"
#include "Commands/TurretPIDChange.h"
#include "Commands/ToggleTwist.h"

OI::OI() {
	driveStick = new Joystick(DRIVESTICK_PORT);
	opStick = new Joystick(OPSTICK_PORT);
	buttonStick = new Joystick(BUTTONSTICK_PORT);

//Set button names equal to their button on the joystick


	driveButton1 = new JoystickButton (driveStick, 1);
	driveButton2 = new JoystickButton (driveStick, 2);
	driveButton3 = new JoystickButton (driveStick, 3);
	driveButton4 = new JoystickButton (driveStick, 4);
	driveButton5 = new JoystickButton (driveStick, 5);
	driveButton6 = new JoystickButton (driveStick, 6);
	driveButton7 = new JoystickButton (driveStick, 7);
	driveButton8 = new JoystickButton (driveStick, 8);
	driveButton9 = new JoystickButton (driveStick, 9);
	driveButton10 = new JoystickButton (driveStick, 10);
	driveButton11 = new JoystickButton (driveStick, 11);
	driveButton12 = new JoystickButton (driveStick, 12);
	
	opButton1 = new JoystickButton (opStick, 1);
	opButton2 = new JoystickButton (opStick, 2);
	opButton3 = new JoystickButton (opStick, 3);
	opButton4 = new JoystickButton (opStick, 4);
	opButton5 = new JoystickButton (opStick, 5);
	opButton6 = new JoystickButton (opStick, 6);
	opButton7 = new JoystickButton (opStick, 7);
	opButton8 = new JoystickButton (opStick, 8);
	opButton9 = new JoystickButton (opStick, 9);
	opButton10 = new JoystickButton (opStick, 10);
	opButton11 = new JoystickButton (opStick, 11);
	opButton12 = new JoystickButton (opStick, 12);

	buttonButton1 = new JoystickButton (buttonStick, 1);
	buttonButton2 = new JoystickButton (buttonStick, 2);
	buttonButton3 = new JoystickButton (buttonStick, 3);
	buttonButton4 = new JoystickButton (buttonStick, 4);
	buttonButton5 = new JoystickButton (buttonStick, 5);
	buttonButton6 = new JoystickButton (buttonStick, 6);
	buttonButton7 = new JoystickButton (buttonStick, 7);
	buttonButton8 = new JoystickButton (buttonStick, 8);
	buttonButton9 = new JoystickButton (buttonStick, 9);
	buttonButton10 = new JoystickButton (buttonStick, 10);
	buttonButton11 = new JoystickButton (buttonStick, 11);
	buttonButton12 = new JoystickButton (buttonStick, 12);
	
//	driveButton1
//	driveButton2
	driveButton3->WhenPressed(new TrimGyro(TrimGyro::fineLeft));
	driveButton4->WhenPressed(new TrimGyro(TrimGyro::fineRight));
	driveButton5->WhenPressed(new TrimGyro(TrimGyro::coarseLeft));
	driveButton6->WhenPressed(new TrimGyro(TrimGyro::coarseRight));
	driveButton7->WhenPressed(new TrimGyro(TrimGyro::zero));
	driveButton8->WhenPressed(new ToggleTwist());
	driveButton9->WhileHeld(new MoveTipper(Tipper::extend));
	driveButton10->WhileHeld(new MoveTipper(Tipper::extend));
	driveButton11->WhenPressed(new MoveTipper(Tipper::retract));
	driveButton12->WhenPressed(new MoveTipper(Tipper::retract));

#ifdef SIMULATE
//	opButton1
//	opButton2
	opButton3->WhenPressed(new TurretPIDChange(-0.001,0,0));
	opButton4->WhenPressed(new TurretPIDChange(0,-0.001,0));
	opButton5->WhenPressed(new TurretPIDChange(0.001,0,0));
	opButton6->WhenPressed(new TurretPIDChange(0,0.001,0));
//	opButton7
//	opButton8
//	opButton9
	opButton10->WhileHeld(new AutoAim());
//	opButton11
//	opButton12
#else 
	opButton1->WhenPressed(new Fire());
	opButton2->WhenPressed(new PrimeShooter());
	opButton3->WhileHeld(new AutoCollect());
//	opButton4
//	opButton5
	opButton6->WhileHeld(new ManualMoveElevator(Elevator::moveUp));
	opButton7->WhileHeld(new ManualMoveElevator(Elevator::moveDown));
	opButton8->WhenPressed(new MoveUp());
	opButton9->WhenPressed(new MoveDown());
//	opButton10
//	opButton11
//	opButton12
#endif
	
// remoted for practice			buttonButton1->WhileHeld(new AutoAim());
//	buttonButton2
// remoted for practice			buttonButton3->WhileHeld(new AutoRange());
//	buttonButton3
//	buttonButton4
	buttonButton5->WhileHeld(new Eject());
//	buttonButton6
	buttonButton7->WhileHeld(new BallCollect());
	buttonButton7->WhenReleased(new NoBallColletion());
//	buttonButton8
	buttonButton9->WhileHeld(new AutoCollect());
//	->WhenPressed (new AutoLevel());
//	buttonButton10
//	buttonButton11
//	buttonButton12
	
/*	
	//driveStick buttons	
	autoLevel = new JoystickButton (driveStick, 2);
	fineTrimLeft = new JoystickButton (driveStick, 3);
	fineTrimRight = new JoystickButton (driveStick, 4);
	coarseTrimLeft = new JoystickButton (driveStick, 5);
	coarseTrimRight = new JoystickButton (driveStick, 6);
	zeroGyro = new JoystickButton (driveStick, 7);
	disableTwist = new JoystickButton (driveStick, 8);
	extendTipper1 = new JoystickButton (driveStick, 9);
	extendTipper2 = new JoystickButton (driveStick, 10);
	retractTipper1 = new JoystickButton (driveStick, 11);
	retractTipper2 = new JoystickButton (driveStick, 12);
//opStick buttons
	trigger = new JoystickButton(opStick, 1); // 1 is equal to Joystick::kTriggerButton in this case
	prime1 = new JoystickButton (opStick, 2);
	prime2 = new JoystickButton (opStick, 3);
	prime3 = new JoystickButton (opStick, 4);
	prime4 = new JoystickButton (opStick, 5);
	manualElevUp = new JoystickButton (opStick, 6); //fix number
	manualElevDown = new JoystickButton (opStick, 7); //fix number
	elevUpSlot = new JoystickButton (opStick, 8); //fix number
	elevDownSlot = new JoystickButton (opStick, 9); //fix number
//buttonStick buttons
	autoAimOn = new JoystickButton (buttonStick, 1);
//	autoAimOff = new JoystickButton (buttonStick, 2);
	autoRangeOn = new JoystickButton (buttonStick, 3);
//	autoRangeOff = new JoystickButton (buttonStick, 4);
	ballSweepIn = new JoystickButton (buttonStick, 7);
//	ballSweepOff = new JoystickButton (buttonStick, 6);
	ballSweepOut = new JoystickButton (buttonStick, 5);
	autoLevel= new JoystickButton (buttonStick, 9);
// Simulation buttons
//	toTheLeft = new JoystickButton (driveStick, 1);
//	toTheRight = new JoystickButton (driveStick, 2);

//Tell the buttons what to do when pressed or held

//driverStick buttons
	fineTrimLeft->WhenPressed(new TrimGyro(TrimGyro::fineLeft));
	fineTrimRight->WhenPressed(new TrimGyro(TrimGyro::fineRight));
	coarseTrimLeft->WhenPressed(new TrimGyro(TrimGyro::coarseLeft));
	coarseTrimRight->WhenPressed(new TrimGyro(TrimGyro::coarseRight));
	zeroGyro->WhenPressed(new TrimGyro(TrimGyro::zero));
	disableTwist->WhenPressed(new ToggleTwist());
	extendTipper1->WhileHeld(new MoveTipper(Tipper::extend));
	extendTipper2->WhileHeld(new MoveTipper(Tipper::extend));
	retractTipper1->WhenPressed(new MoveTipper(Tipper::retract));
	retractTipper2->WhenPressed(new MoveTipper(Tipper::retract));
//opStick buttons
	trigger->WhenPressed(new Fire());
	
	manualElevUp->WhileHeld(new ManualMoveElevator(Elevator::moveUp));
	manualElevDown->WhileHeld(new ManualMoveElevator(Elevator::moveDown));
	elevUpSlot->WhenPressed(new MoveUp());
	elevDownSlot->WhenPressed(new MoveDown());
	prime1->WhenPressed(new PrimeShooter());
	// Review: prime2 = button 3
	prime2->WhileHeld(new AutoCollect());
//	 Review: chenged to AutoCollect temporarily
//	prime3->WhenPressed(new AutoCollect());
//	prime4->WhenPressed(new PrimeShooter());
//buttonStick buttons
	autoAimOn->WhileHeld(new AutoAim());
//	autoAimOn->WhenReleased(new ManualAim()); 
	autoRangeOn->WhileHeld(new AutoRange());
	autoRangeOn->WhenReleased(new ManualRange());
	ballSweepIn->WhileHeld(new BallCollect());
	ballSweepIn->WhenReleased(new NoBallColletion());
	ballSweepOut->WhileHeld(new Eject());
	autoLevel->WhenPressed (new AutoLevel);
//	toTheLeft->WhenPressed(new RotateLeft());
//	toTheRight->WhenPressed(new RotateRight());
 */
}
Joystick * OI::getDriveStick() {
	return driveStick;
}
Joystick * OI::getOpStick() {
	return opStick;
}
Joystick * OI::getButtonStick() {
	return buttonStick;
}

float OI::getOpStickXAxis()
{
	float xAxis;
	xAxis = opStick->GetAxis(Joystick::kXAxis);
	return xAxis;
}

float OI::getSliderPower()
{
	float yAxis;
#if defined (SIMULATE)
	yAxis = max(0 , -opStick->GetAxis(Joystick::kYAxis) * 5);
#else
	yAxis = -buttonStick->GetAxis(Joystick::kYAxis)*4;
#endif
	return yAxis;
}
