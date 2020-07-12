// File: demo.pov
// Desc: well.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "../environment.inc"
#include "well.inc"

camera {
	location  <0.0, 0.5, -3.0>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
}

//Well(7, 0, 1, .7, .4, 1, 15, 5, .05, .5, .25, false)
//Well(7, 0, 4, .7, .4, 20, 12, 5, .05, .5, .25, false)
//object { Well(1, 0, 5, .7, .4, 35, 20, 5, 0.5, .5, 1, true) translate <-2, 0, 0> }
//object { Well(4, 0, 5, .7, .4, 35, 16, 5, 0.5,.5, 1, true) translate <2, 0, 0> }


Well(7, 0, 4, .7, .4, 20, 12, 5, .05, .5, .25, true)
