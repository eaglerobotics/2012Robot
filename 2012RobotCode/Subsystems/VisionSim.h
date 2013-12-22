#ifndef VisionSim_H
#define VisionSim_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "VisionBase.h"

/**
 *
 *
 * @author Jarrett	
 */
class VisionSim: public VisionBase {
private:
	
public:
	VisionSim();
	virtual void InitDefaultCommand();
	
	/*
	 * Analyze the image and the number of targets found
	 */
	virtual int particleAnalysis();
	
	/**
	 * Set which particle in the vector to use as the target
	 */
	virtual void setTargetParticle(int index);
	
	/**
	 * Gets a normalized x distance from the center of the screen
	 * 
	 * @return A number between -1.0 and 1.0 representing the distance from the center
	 */
	virtual double getNormalizedXPosition();
	
	/**
	 * Gets the x coordinate of particle
	 */
	virtual int getXPosition();
	
	/**
	 * Gets a normalized y distance from the center of the screen
	 * 
	 * @return A number between -1.0 and 1.0 representing the distance from the center
	 */
	virtual double getNormalizedYPosition();
	
	/**
	 * Gets the y coordinate of particle
	 */
	virtual int getYPosition();
	
	/*
	 * Use the pixel count of the rectangle to determine distance in inches
	 */
	virtual float getDistance();
	
	/*
	 * Sets the Camera to high Resolution for acquiring a good image so
	 * we can be accurate when shooting
	 */
	virtual void setHighRes();
	
	/*
	 * Sets the camera to low resolution so that we can get a higher framerate
	 * for the original acquisition of the target
	 */
	virtual void setLowRes();
	
	virtual int getNumberOfTargets();
	/*
	 * gets the number of targets in the camera's field of view
	 */
};

#endif
