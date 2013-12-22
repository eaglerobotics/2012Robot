#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "VisionBase.h"

/**
 *
 *
 * @author eaglerobotics
 */
class Vision: public VisionBase {
private:
	
	Relay *lightRing;
	
	// Need to tweek this number based off distance
	static const double MIN_PARTICLE_AREA = 100;
	
	// Review: Check the constants for improved lighting
	static const AxisCamera::Resolution_t CAMERA_LOW_RESOLUTION = AxisCamera::kResolution_320x240;
	static const AxisCamera::Resolution_t CAMERA_HIGH_RESOLUTION = AxisCamera::kResolution_640x480;
	static const int CAMERA_COMPRESSION = 30;
	static const int CAMERA_BRIGHTNESS = 50;
	static const int CAMERA_FPS = 15;
	static const int CAMERA_COLOR_LEVEL = 75;
	static const AxisCamera::WhiteBalance_t CAMERA_WHITE_BALANCE = AxisCamera::kWhiteBalance_FixedFlourescent1; 
	// Can't find a way to set this. Will use if we find a way.
	// Testing shows that Exposure level is persistant through power cycles.
//	static const int CAMERA_EXPOSURE_LEVEL = 0; 
	
#define COLOR_THRESHOLD 0,200,200,255,0,255
	
	// Varialbe to store the rectangle mathces
	vector<ParticleAnalysisReport> *particles;
	ParticleAnalysisReport targetParticle;
public:
	Vision();
	void InitDefaultCommand();
	
	/*
	 * Analyze the image and the number of targets found
	 */
	int particleAnalysis();
	
	/**
	 * Set which particle in the vector to use as the target
	 */
	void setTargetParticle(int index);
	
	/**
	 * Gets a normalized x distance from the center of the screen
	 * 
	 * @return A number between -1.0 and 1.0 representing the distance from the center
	 */
	double getNormalizedXPosition();
	
	/**
	 * Gets the x coordinate of particle
	 */
	int getXPosition();
	
	/**
	 * Gets a normalized y distance from the center of the screen
	 * 
	 * @return A number between -1.0 and 1.0 representing the distance from the center
	 */
	double getNormalizedYPosition();
	
	/**
	 * Gets the y coordinate of particle
	 */
	int getYPosition();
	
	/*
	 * Use the pixel count of the rectangle to determine distance in inches
	 */
	float getDistance();
	
	/*
	 * Sets the Camera to high Resolution for acquiring a good image so
	 * we can be accurate when shooting
	 */
	void setHighRes();
	
	/*
	 * Sets the camera to low resolution so that we can get a higher framerate
	 * for the original acquisition of the target
	 */
	void setLowRes();
	
	/*
	 * gets the number of targets in the camera's field of view
	 */
	int getNumberOfTargets();
	
};

#endif
