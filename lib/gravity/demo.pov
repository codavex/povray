// File: demo.pov
// Desc: grabity.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "../environment.inc"
#include "gravity.inc"

camera {
	location  <0.0, 0.5, -3.0>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
}

#declare ball = object {
  sphere { <0,0,0> .05 }
  texture { pigment { colour White } }
}

#declare shift = -3;
#while (shift < 3)
  object { gravity_trajectory(ball, 1.8, 0) translate <shift, 0, 0> }
  #declare shift = shift + 0.1;
#end

