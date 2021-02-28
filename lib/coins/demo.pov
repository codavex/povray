// File: demo.pov
// Desc: coin.inc demo

#version 3.7;

global_settings { assumed_gamma 1.0 }

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	  // Standard Color definitions

#include "coins.inc"

camera {
  location  <0.0, 0.0,-0.06>
  right     x*image_width/image_height
}

light_source {
  <500, 500, -500>
  color rgb <1,1,1>
}

object { silver_coin          rotate x*-90 rotate y*180 rotate y*clock*90 translate <-.025, 0, 0> }
object { silver_and_gold_coin rotate x*-90 rotate y*180 rotate y*clock*90 }
object { copper_coin          rotate x*-90 rotate y*180 rotate y*clock*90 translate < .025, 0, 0> }
