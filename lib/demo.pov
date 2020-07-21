// File: demo.pov
// Desc: fountain.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "environment.inc"

camera {
        location <0.0, .5, -4>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
}
