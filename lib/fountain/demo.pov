// File: demo.pov
// Desc: fountain.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "../environment.inc"
#include "fountain.inc"

camera {
	location  <0.0, 0.5+(5*clock/60), -4.0>
	location  <0, 4, -4>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
	rotate    <0, -3*clock, 0>
}

object { fountain }
