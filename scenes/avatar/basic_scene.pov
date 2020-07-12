// File: environment.inc
// Desc: basic environment

#version 3.7;

#include "colors.inc"

global_settings { assumed_gamma 1.0 }

camera {
  location  <0.0, 1.5, -3.0>
  look_at   <0.0, 1.0,  0.0>
  right     x*image_width/image_height
}

// The Sun
light_source {
  <500, 500, -500>
  color rgb <1,1,1>
}

// sky
plane {
  <0,1,0>,10000 hollow  //
  texture {
    pigment {
      color rgb<0.2,0.5,0.8>
    }
    finish { ambient 1 diffuse 0 }
  }
}

plane {
  <0,1,0>,1 hollow  //
  texture {
    pigment {
      bozo turbulence 0.65
      octaves 6  omega 0.7 lambda 2
      color_map { [0.0 color rgb <0.95, 0.95, 0.95>]
                  [0.1 color rgb <0.85, 0.85, 0.85>]
                  [0.5 color rgbt <1, 1, 1, 1> ]
                  [1.0 color rgbt <1, 1, 1, 1> ] }
      rotate<10,20,0>
      scale <0.3, 0.4, 0.2>*3
    }
    finish {ambient 1 diffuse 0}
  }
  scale 1000
}

plane {
  <0,1,0> 0 hollow
  texture { pigment { checker pigment{White}, pigment{Black} } }
}

// fog at the horizon
fog{distance 300000 color White}

object {
  sphere { <0, 1, 0> .8 }
  texture { finish { reflection {1.0} ambient 0 diffuse 0 } }
}
