//Author: Sheridan Rea
#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	static const int DRIVESTICK_PORT = 1;
	static const int OPSTICK_PORT = 2;
	static const int BUTTONSTICK_PORT = 3;

	Joystick *driveStick;	
	Joystick *opStick;
	Joystick *buttonStick;

	JoystickButton *driveButton1;
	JoystickButton *driveButton2;
	JoystickButton *driveButton3;
	JoystickButton *driveButton4;
	JoystickButton *driveButton5;
	JoystickButton *driveButton6;
	JoystickButton *driveButton7;
	JoystickButton *driveButton8;
	JoystickButton *driveButton9;
	JoystickButton *driveButton10;
	JoystickButton *driveButton11;
	JoystickButton *driveButton12;
	
	JoystickButton *opButton1;
	JoystickButton *opButton2;
	JoystickButton *opButton3;
	JoystickButton *opButton4;
	JoystickButton *opButton5;
	JoystickButton *opButton6;
	JoystickButton *opButton7;
	JoystickButton *opButton8;
	JoystickButton *opButton9;
	JoystickButton *opButton10;
	JoystickButton *opButton11;
	JoystickButton *opButton12;
	
	JoystickButton *buttonButton1;
	JoystickButton *buttonButton2;
	JoystickButton *buttonButton3;
	JoystickButton *buttonButton4;
	JoystickButton *buttonButton5;
	JoystickButton *buttonButton6;
	JoystickButton *buttonButton7;
	JoystickButton *buttonButton8;
	JoystickButton *buttonButton9;
	JoystickButton *buttonButton10;
	JoystickButton *buttonButton11;
	JoystickButton *buttonButton12;
/*
	//Define driveStick buttons 
	JoystickButton *autoLevel; //2
	JoystickButton *fineTrimLeft; //3
	JoystickButton *fineTrimRight; //4
	JoystickButton *coarseTrimLeft; //5
	JoystickButton *coarseTrimRight; //6
	JoystickButton *zeroGyro; //7
	JoystickButton *disableTwist; //8
	JoystickButton *extendTipper1; //9
	JoystickButton *extendTipper2; //10
	JoystickButton *retractTipper1; //11
	JoystickButton *retractTipper2; //12
	
//Define opStick buttons
	JoystickButton *trigger; //1
	JoystickButton *manualElevUp; //6 fix button num
	JoystickButton *manualElevDown; //7 fix button num
	JoystickButton *elevUpSlot; //8 fix button num
	JoystickButton *elevDownSlot; //9 fix button num
	JoystickButton *prime1; //2
	JoystickButton *prime2; //3
	JoystickButton *prime3; //4
	JoystickButton *prime4; //5
	JoystickButton *manualAimOn; // 8 Simulation
//Define buttonStick buttons
 	JoystickButton *autoAimOn; //1
//	JoystickButton *autoAimOff; //2
	JoystickButton *autoRangeOn; //3
//	JoystickButton *autoRangeOff; //4
	JoystickButton *ballSweepIn; //5
	JoystickButton *ballSweepOff; //6
	JoystickButton *ballSweepOut; //7
*/
	
public:
	OI();
	Joystick *getDriveStick();
	Joystick *getOpStick();
	Joystick *getButtonStick();
	float getOpStickXAxis();
	float getSliderPower();
};
#endif


//#ifndef OI_H
//#define OI_H
//
//#include "WPILib.h"
//
//class OI {
//private:
//	static const int DRIVER_STICK_PORT = 1;
//	// SHOOTER = operator
//	static const int SHOOTER_STICK_PORT = 2;
//	
//	static const int IO_STICK_PORT = 3;
//
//	
//	Joystick *joystick;
//	Joystick *opsStick;
//	Joystick *ioStick;
//
//public:
//	
//	/*
//	 * This is were the Ops stick constants are.
//	 * If you want to access a button on the control board, you would first
//	 * call <code>getOpsStick()</code>. Then you would call <code>GetRawButton</code>
//	 * from the ops stick joystick you got in the last function
//	 * Example: You want the tipper switch
//	 * <code>
//	 * Joystick *opsStick = getOpsStick();
//	 * bool tipperSwitch = opsStick->GetRawButton(TIPPER_SWITCH_BUTTON);
//	 * </code>
//	 */
//	static const int TIPPER_SWITCH_BUTTON = 1;
//	
//	static const int NUM_JOYSTICK_BUTTONS = 12;
//	
//	OI();
//	Joystick *getJoystick();
//	Joystick *getOpsStick();
//	Joystick *getIOStick();
//};
//
//#endif
