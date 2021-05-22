// File: demo.pov
// Desc: grabity.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "environment.inc"
#include "projectile.inc"

camera {
	location  <0.0, 0.5, -3.0>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
}

#declare ball = object {
  sphere { <0,0,0> .05 }
  texture { pigment { colour White } }
}

#declare shift = 0;
#while (shift < 360)
  object { projectile_trajectory(ball, 1, 60, 3) rotate <0, shift, 0> }
  #declare shift = shift + 30;
#end

