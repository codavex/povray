#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	// Standard Color definitions
#include "textures.inc"	// Standard Texture definitions

// set viewer's position in the scene
camera {
  location  <.66, -0.5, -1.5>
  direction 1.5*z
  right     x*image_width/image_height
  look_at   <.66, 0.0, 0.0>
}

light_source { <500, 500, -500> color White }

object { sphere { <1,0,0> .1 } texture { Chrome_Metal } rotate y*000 rotate y*90*clock rotate z*-20}
object { sphere { <1,0,0> .1 } texture { Chrome_Metal } rotate y*090 rotate y*90*clock rotate z*20}
object { sphere { <1,0,0> .1 } texture { Chrome_Metal } rotate y*180 rotate y*90*clock rotate z*-20}
object { sphere { <1,0,0> .1 } texture { Chrome_Metal } rotate y*270 rotate y*90*clock rotate z*20}

