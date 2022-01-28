// File: symmetry_test.pov
// Desc: demo image for symmetry script

#version 3.7;

global_settings { assumed_gamma 1.0 }

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions


camera {
  location  <0.0, 0.0,-6>
  right     x*image_width/image_height
}

light_source {
  <500, 500, -500>
  color rgb <1,1,1>
}

object {
  cylinder { <0,-10,0> <0,10,0> .25 }
  texture { pigment { color Red } }
  rotate z*-45
}

object {
  cylinder { <0,-10,0> <0,10,0> .25 }
  texture { pigment { color Blue } }
  rotate z*-45
  translate x*-4
}

object {
  cylinder { <0,-10,0> <0,10,0> .25 }
  texture { pigment { color Green } }
  rotate z*-45
  translate x*4
}

