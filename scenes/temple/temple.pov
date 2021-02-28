#version 3.7;

// ==== Standard POV-Ray Includes ====
#include "colors.inc"	// Standard Color definitions
#include "textures.inc"	// Standard Texture definitions
#include "stones.inc"

global_settings { assumed_gamma 1.0 }

#declare SMALL = 0.015;
   
#declare p1 = <0.0,  15.0, -40.0>;
#declare p2 = <40.0, 10.0,  40.0>;
#declare p3 = <3.0,   5.0,   0.0>;
#declare p4 = <0.0,  -2.0,   0.0>;
                   
#declare time = clock;
#declare ripples_clock = clock;
#declare ap1 = (1-time)*(1-time)*(1-time)*p1;
#declare ap2 = 3*(1-time)*(1-time)*time*p2;
#declare ap3 = 3*(1-time)*time*time*p3;                   
#declare ap4 = time*time*time*p4;
#declare cam_loc = ap1 + ap2 + ap3 + ap4;

// set viewer's position in the scene
camera {
  direction <0.0, 0.0,  2.0> // which way are we looking <X Y Z> & zoom
  up        <0.0, 1.0,  0.0> // which way is +up <X Y Z>
  right     <4/3, 0.0,  0.0> // which way is +right <X Y Z> and aspect ratio
//  location cam_loc
//  location  <0.0, 5.0, -40.0> // position of camera <X Y Z>
  location  <0.0, 15.0, -40.0> // position of camera <X Y Z>
//  location  <0.0, 3.0, -6.0> // position of camera <X Y Z>
//  location  <3.0, 3.0, -10.0> // position of camera <X Y Z>
  look_at   <0.0, -2.0-SMALL,  0.0> // point center of view at this point <X Y Z>
}

// create a regular point light source
light_source { <-20, 40, -20> color White }
//light_source { <-5, 5, -5> color White }

// FLOOR
#declare Floor = object {
  plane { y, -1.0 }
  texture { pigment { SteelBlue filter 0.6 } }
  normal { ripples 0.1 phase ripples_clock}
}

#declare Sky = object {
  sphere { <0, 0, 0>, 1 }
  texture { Starfield }
  texture {
    pigment {
      gradient y
      color_map {
        [0.000 0.400 color NavyBlue  color Clear ]
        [0.400 1.000 color Clear color Clear ]
      }
    }
  }
  scale 1000
  no_shadow
  hollow
}

#declare Piller_Post = object {
  cylinder { <0,-1,0> <0,2,0> 0.2 }
}

#declare Piller_Block = object {
  union {
    cylinder { <0, 0, 0> <0, 1, 0> .3 }
    difference {
      cylinder { <0, 0+SMALL, 0> <0, 1-SMALL, 0> .65 }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 000, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 030, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 060, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 090, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 120, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 150, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 180, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 210, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 240, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 270, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 300, 0> }
      object { Piller_Post translate <0.6, 0, 0> rotate <0, 330, 0> }
    }
  }
  texture { T_Grnt16 } //pigment { color White } }
}

#declare Piller = object {
  union {
    object { Piller_Block translate <0, 0, 0> }
    object { Piller_Block translate <0, 1, 0> }
    object { Piller_Block translate <0, 2, 0> }
    object { Piller_Block translate <0, 3, 0> }
    object { Piller_Block translate <0, 4, 0> }
  }
}

#declare Columns = object {
  union {
    object { Piller translate <7, 0, 0> rotate <0, 000, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 030, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 060, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 090, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 120, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 150, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 180, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 210, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 240, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 270, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 300, 0> }
    object { Piller translate <7, 0, 0> rotate <0, 330, 0> }
  }
}

#declare MosTex = texture {
  pigment {
    crackle
    color_map {
      [0.05 colour White ]
      [0.08 colour Flesh ]
      [0.10 colour Flesh ]
      [1.00 colour Tan   ]
    }
  }
  scale 0.25
}

#declare Steps = object {
  difference {
    object {
      union {
        cylinder { <0,-1.0,0> <0,-0.6,0> 10 }
        cylinder { <0,-0.6,0> <0,-0.3,0>  9 }
        difference {
          cylinder { <0,-0.3,0> <0,0.0,0> 8 }
          cylinder { <0,-5.0,0> <0,5.0,0> 6 }
        }
        object { cylinder { <0,-0.3,0> <0,-0.05,0>  7.0 } texture { MosTex } }
        object { cylinder { <0,-0.3,0> <0, 0.20,0>  2.5 } }
      }
    }
    object { sphere { <0, 0, 0> 2 } scale <1, 1/3, 1> }
    object { cylinder { <0, 0, 0> <0, 3, 0> 2 } }
    object { cylinder { <0, -.9, 0> <0, 3, 0> .5 } }
  }
  texture { T_Grnt16 } // pigment { color White } }
}

#declare Roof = object {
  union {
    difference {
      cylinder { <0, 5.00,0> <0,5.10,0> 7.8 }
      cylinder { <0, 4.00,0> <0,7.00,0> 6.2 }
    }
    difference {
      cylinder { <0, 5.10,0> <0,5.56,0> 7.6 }
      cylinder { <0, 4.00,0> <0,7.00,0> 6.4 }
    }
    difference {
      cylinder { <0, 5.56,0> <0,5.66,0> 7.8 }
      cylinder { <0, 4.00,0> <0,7.00,0> 6.2 }
    }
  }
  texture { T_Grnt16 } //pigment { color White } }
}

#declare Spring = object {
  box { <-4, -1, -4> <4, -.06, 4> }
  texture {
    pigment{ color SteelBlue }
    normal {
      ripples 0.75
      frequency 10  
      phase ripples_clock
    }
    finish {
      reflection 0.2
      // refraction 0.5 // old version
    }
    scale 3
  }
  interior {
    ior 1.33
  }
}

#declare Temple = object {
  union {
    object { Spring }
    object { Steps }
    object { Columns }
    object { Roof }
  }
}

object { Temple }
object { Floor }
//object { Sky }
