// Desc: Aboriginal Dot Art

#version 3.7;

#include "colors.inc"

#include "dot_art.inc"

global_settings { assumed_gamma 1.0 }

camera {
  location  <0, 0, -4>
  direction 1.5*z
  right     x*image_width/image_height
  look_at   <0, 0, 0>
}

background { color rgb 0 }

light_source {
  <0, 0, 0>
  color rgb <1, 1, 1>
  translate <-30, 30, -30>
}

#declare dot_height=4;
#declare dot_length=4;

#declare p1=pigment {
  marble
  turbulence 0.8
  //lambda 1.3
  //omega .7
  //octaves 5
  //frequency 3
  color_map {
    [0.00 color Black]
    [0.10 color <.2, 0, 0>]
    [0.48 color Red]
    [0.50 color Firebrick]
    [0.52 color Red]
    [0.90 color Red]
    [0.98 color Orange]
    [1.00 color White]
  }
  rotate <0,0,30>
  scale 2
}

#declare fn_Pigm=function {
  pigment { p1 }
}

#declare dots=object {
  union {
    dot_art(dot_length, dot_height, .01, .01, 1.2, fn_Pigm)
  }
  translate <-dot_length/2, -dot_height/2, 0>
}

object { dots }
//object { plane {z, 0} texture { pigment { p3 } } }
