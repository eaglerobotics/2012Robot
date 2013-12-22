#include "Vision.h"
#include "../Util.h"
#include "../Robotmap.h"

#undef DEBUG_MODE
#define DEBUG_MODE true

Vision::Vision() : VisionBase() {
	TracePrint(TRACE_VISION, "Initializing Camera Settings.");
	
	// Get an instance of the camera
	AxisCamera &camera = AxisCamera::GetInstance(CAMERA_IP);
	
	// Write some configuration to the camera
	camera.WriteResolution(CAMERA_LOW_RESOLUTION);
	camera.WriteCompression(CAMERA_COMPRESSION);
	camera.WriteBrightness(CAMERA_BRIGHTNESS);
	camera.WriteMaxFPS(CAMERA_FPS);
	camera.WriteColorLevel(CAMERA_COLOR_LEVEL);
	
	TracePrint(TRACE_VISION, "Done Configuring Camera.");
	
	particles = NULL;
	
	lightRing = new Relay(DEFAULT_DIGITAL_MODULE, LIGHT_RING_PORT, Relay::kForwardOnly);
	lightRing->Set(Relay::kOn);
	
}    
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

int Vision::particleAnalysis()
{
	printf("Vision::particleAnalysis\n");
	// Get an instance of the Axis Camera
	AxisCamera &camera = AxisCamera::GetInstance(CAMERA_IP);
	
	TracePrint(TRACE_VISION, "check fresh\n");
	// check if there is a new image
	if (camera.IsFreshImage())
	{
		TracePrint(TRACE_VISION, "get image\n");
		// Get the Image
		ColorImage *colorImage = camera.GetImage();
		TracePrint(TRACE_VISION, "colorImage is %s\n", colorImage ? "not null" : "null");
		BinaryImage *binImage = colorImage->ThresholdRGB(COLOR_THRESHOLD);
		TracePrint(TRACE_VISION, "binImage is %s\n", binImage ? "not null" : "null");
		
		if(!colorImage || !binImage)
			return -1;
		
		TracePrint(TRACE_VISION, "Getting Particle Analysis Report.");
		if (particles)
		{
			delete particles;
		}
		particles = binImage->GetOrderedParticleAnalysisReports();
		if(!particles)
		{
			TracePrint(TRACE_VISION, "NULL PARTICLES");
			return -1;
		}
		if(!particles->empty())
		{
			TracePrint(TRACE_VISION, "Stepping through particle report to remove particles with area too small (total %d particles).\n", particles->size());

			int maxHeight = 0, maxIndex = -1;

			// Step through the particles and elimate any that are too small
			for (int i = 0; i<(int)particles->size(); i++) 
			{
				TracePrint(TRACE_VISION, "Particle %d:\n", i);
				TracePrint(TRACE_VISION, "area %.4lf\n", particles->at(i).particleArea);
				
				if(particles->at(i).particleArea<MIN_PARTICLE_AREA)
				{
					TracePrint(TRACE_VISION, "Particle too small, erasing... ");
					
					// Erase the current particle from view
					particles->erase(particles->begin()+i);
					
					// Because erasing an element actually adjusts all elements
					// after the current one, we need to bump <tt>i</tt> down one
					i--;
					TracePrint(TRACE_VISION, "... erased.\n");
				}
				else
				{
					TracePrint(TRACE_VISION, "Checking height...");
					if (particles->at(i).center_mass_y>maxHeight) {
						maxIndex = i;
						maxHeight = particles->at(i).center_mass_y;
					}
					TracePrint(TRACE_VISION, "... checked\n");
				}
			}
			if (maxIndex!=-1)
				targetParticle = particles->at(maxIndex);
		}
		else 
		{
			targetParticle.center_mass_x_normalized = 0;
		}
		
		if (colorImage)
		{
			printDebug("Deleting colorImages.");
			delete colorImage;
		}
		if (binImage)
		{
			printDebug("Deleting binImages.");
			delete binImage;
		}
		
		printDebug("Done Deleting Images.");
	}
	
	printDebug("Done processing image.");
	
	return particles->size();
}

void Vision::setTargetParticle(int index)
{
	if(index < (int)particles->size())
		targetParticle = particles->at(index);
}

double Vision::getNormalizedXPosition()
{
	return targetParticle.center_mass_x_normalized;
}

int Vision::getXPosition()
{
	return targetParticle.center_mass_x;
}

double Vision::getNormalizedYPosition()
{
	return targetParticle.center_mass_x_normalized;
}

int Vision::getYPosition()
{
	return targetParticle.center_mass_y;
}

float Vision::getDistance()
{
	// This relationship was determined using LoggerPro
	if(!targetParticle.boundingRect.height)
		return 7327.0/(float)targetParticle.boundingRect.height;
	else 
		return 0;
}

void Vision::setHighRes()
{
	AxisCamera &camera = AxisCamera::GetInstance(CAMERA_IP);
	camera.WriteResolution(CAMERA_HIGH_RESOLUTION);
}

void Vision::setLowRes()
{
	AxisCamera &camera = AxisCamera::GetInstance(CAMERA_IP);
	camera.WriteResolution(CAMERA_LOW_RESOLUTION);
}

int Vision::getNumberOfTargets()
{
	return particles->size();
}
