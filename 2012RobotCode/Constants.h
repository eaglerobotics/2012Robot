#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "WPIlib.h"

// ==========================================================================
// START GENERAL CONSTANTS
// ==========================================================================

static const double LOOP_PERIOD = 0.02;

// ==========================================================================
// END GENERAL CONSTANTS
// ==========================================================================

// ===========================================================================
// START CAMERA CONSTANTS
// ===========================================================================

// IP of the Camera
//#define CAMERA_IP "10.13.88.11"

/* We will be using 640x480. That is the resolution that FIRST suggests and
 * we see no reason why this shouldn't be fine, but we might decide to lower
 * it if there is too much lag due to vision processing
 */
static const AxisCamera::Resolution_t CAMERA_RESOLUTION = AxisCamera::kResolution_640x480;

/* 20 is kinda the default compression so we will keep it
 * this way for now.
 */
static const int CAMERA_COMPRESSION = 20;

/* The FIRST example sets the brightness to 0 so I will too
 * We will goof around with this number to see if it's fine
 */
static const int CAMERA_BRIGHTNESS = 0;

/* We will be using a frame-rate of 15 fps. We may decide to lower this
 * if we are encountering to much lag.
 */
static const int CAMERA_FPS = 15;

// ===========================================================================
// END CAMERA CONSTANTS
// ===========================================================================

#endif
