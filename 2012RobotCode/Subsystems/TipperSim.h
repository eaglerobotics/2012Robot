#ifndef TIPPERSIM_H
#define TIPPERSIM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "TipperBase.h"

/**
 *
 *
 * @author Jarrett
 */
class TipperSim: public TipperBase {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	TipperSim();
	void InitDefaultCommand();
};

#endif
