#ifndef UTIL_H
#define UTIL_H

#include "PIDOutput.h"

/**
 * Returns 0 if abs(input) < range
 * Otherwise, will return a scaled verion of input so that it returns a value -max through max
 * The final value will then be multiplied by scale
 * 
 * NOTE: scale and max are defaulted to 1
 */
float deadband(float input, float range, float scale=1.0, float max=1.0);
void TracePrint(unsigned long lTraceFlags, const char *szFormat, ...);
extern unsigned long glTraceEnableFlags;

#define TRACE_VISION	0x00000001
#define TRACE_AUTOAIM	0x00000002
#define TRACE_TURRET	0x00000004


class manualPIDOutput : public PIDOutput
{
private:
	float value;
	
public:
	virtual void PIDWrite(float output);
	float getValue();
};

#endif
