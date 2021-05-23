// File: demo.pov
// Desc: grabity.inc demo

#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "environment.inc"
#include "projectile.inc"

#declare size_rand = seed (1975);

camera {
	location  <0.0, 0.5, -3.0>
	look_at   <0.0, 0.5,  0.0>
	right     x*image_width/image_height
}

#declare ball = object {
  sphere { <0,0,0> .05 }
  texture { pigment { colour White } }
}

#declare numBalls = 100;
#while ( numBalls > 0)
  object { projectile_trajectory( object { ball scale .9+(rand(size_rand)*.2)  }, 1, 60, 3) }
  #declare numBalls = numBalls - 1;
#end

