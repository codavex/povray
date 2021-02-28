// File: fountain.inc
// Desc: model a fountain with animated water

#version 3.7;

#include "textures.inc"
#include "stones.inc"
#include "glass_old.inc"

#include "physics/gravity/gravity.inc"
#include "column/twisted_column.inc"
#include "coins/coins.inc"

#declare gravity_rand = seed (1975);
#declare coins_rand = seed (1967);

#declare T_Water = texture {
  Glass3
  normal {
    ripples 0.3
    scale 0.25
    turbulence 0.5
    phase clock
    translate< 1,0,2>
  }
  finish {
    ambient 0.45
    diffuse 0.55
    reflection 0.3
  }
}

#declare T_Mosaic = texture {
  pigment {
    crackle
    color_map {
      [0.05 colour White ]
      [0.08 colour Aquamarine ]
      [0.10 colour Aquamarine ]
      [1.00 colour Blue   ]
    }
  }
}

#declare droplet = object {
  sphere { <0,0,0> .007 }
  texture { T_Water }
  interior{ I_Glass }
}

#declare base1 = object {
  cylinder { <0,0,0> <0,.05,0> 2 }
  texture { T_Mosaic scale 0.1 }
}

#declare coins = object {
  union {
    #declare coin_count=0;
    #while (coin_count < 50)
      object { silver_and_gold_coin translate <.5+rand(coins_rand), 0.051, 0> rotate y*360*rand(coins_rand) }
      #declare coin_count=coin_count + 1;
    #end
    #declare coin_count=0;
    #while (coin_count < 100)
      object { silver_coin translate <.5+rand(coins_rand), 0.051, 0> rotate y*360*rand(coins_rand) }
      #declare coin_count=coin_count + 1;
    #end
    #declare coin_count=0;
    #while (coin_count < 200)
      object { copper_coin translate <.5+rand(coins_rand), 0.051, 0> rotate y*360*rand(coins_rand) }
      #declare coin_count=coin_count + 1;
    #end    
  }
}

#declare base = object {
  intersection {
    object {
    union {
      #declare shift = 0;
      #while (shift < 360)
        object { sphere { <0,0.25,0> 1 } scale <.1,1,.2> translate <2, 0, 0> rotate y*shift}
        #declare shift = shift + 10;
      #end
    } }
    plane { -y, 0 }
    plane { y, .5 }
  }
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
}

#declare seat_part = object {
  intersection {
    union {
      difference {
        cylinder { <0,.5,0> <0,.55,0> 2.15 }
        cylinder { <0,0,0> <0, 1, 0> 1.85 }
      }
      object { torus { 2.15, .025 } translate y*.525 }
    }
    object { plane { -z, 0 } rotate y*5 }
    object { plane { z, 0 } rotate y*34.75 }
  }
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
}

#declare seat = object {
  union {
    object { seat_part }
    object { seat_part rotate y*030 }
    object { seat_part rotate y*060 }
    object { seat_part rotate y*090 }
    object { seat_part rotate y*120 }
    object { seat_part rotate y*150 }
    object { seat_part rotate y*180 }
    object { seat_part rotate y*210 }
    object { seat_part rotate y*240 }
    object { seat_part rotate y*270 }
    object { seat_part rotate y*300 }
    object { seat_part rotate y*330 }
    union {
      difference {
        cylinder { <0,.5,0> <0,.54,0> 2.1499 }
        cylinder { <0,0,0> <0, 1, 0> 1.8499 }
      }
      object { torus { 2.1499, .02 } translate y*.52 }
      texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
    }
  }
}

#declare base_water = object {
  cylinder { <0,0,0> <0,.35,0> 2 }
  texture { T_Water }
  interior{ I_Glass }
}

#declare tier1_pillar = object {
  TwistedColumn(.2,1.25,1000)
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
}

#declare tier1_bowl = object {
  difference {
    sphere { <0,0,0> 1.33 }
    plane { -y, 0 }
    sphere { <0,0,0> 1.3 }
  }
  scale <1, .2, 1>
  translate y*1.5
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
}

#declare tier1_bowl_mosaic = object {
  difference {
    sphere { <0,0,0> 1.3 }
    plane { -y, 0 }
    sphere { <0,0,0> 1.299 }
  }
  scale <1, .2, 1>
  translate y*1.5
  texture { T_Mosaic scale 0.1 }
}

#declare tier1_bowl_water = object {
  difference {
    sphere { <0,0,0> 1.315 }
    plane { -y, 0 }
    //sphere { <0,0,0> 0.9 }
  }
  scale <1, .2, 1>
  translate y*1.5
  texture { T_Water }
  interior { I_Glass }
}

#declare shift = 0;
#declare tier1_falling_water = object { union {
#while (shift < 1080)
  object { gravity_trajectory(droplet, 1.5, 0) translate <1.33, 0, 0> rotate y*shift/2}
  #declare shift = shift + 0.5;
#end
} }

#declare tier2_pillar = object {
  TwistedColumn(.1,.865,1000)
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
  translate y*1.25
}

#declare tier2_bowl = object {
  difference {
    sphere { <0,0,0> .67 }
    plane { -y, 0 }
    sphere { <0,0,0> .66 }
  }
  scale <1, .2, 1>
  translate y*2.25
  texture { T_Grnt16 translate <5*rand(gravity_rand),0,0> }
}

#declare tier2_bowl_mosaic = object {
  difference {
    sphere { <0,0,0> .66 }
    plane { -y, 0 }
    sphere { <0,0,0> .6599 }
  }
  scale <1, .2, 1>
  translate y*2.25
  texture { T_Mosaic scale 0.1}
}


#declare tier2_bowl_water = object {
  difference {
    sphere { <0,0,0> .665 }
    plane { -y, 0 }
    //sphere { <0,0,0> 0.9 }
  }
  scale <1, .2, 1>
  translate y*2.25
  texture { T_Water }
  interior { I_Glass }
}

#declare shift = 0;
#declare tier2_falling_water = object { union {
#while (shift < 720)
  object { gravity_trajectory(droplet, .75, 0) translate <0.67, 0, 0> rotate y*shift/2}
  #declare shift = shift + 0.5;
#end
} translate y*1.5 }

#declare fountain = object {
  union {
    object { base1 }
    object { coins }
    object { base }
    object { seat }
    object { base_water }
    object { tier1_pillar }
    object { tier1_bowl }
    object { tier1_bowl_mosaic }
    object { tier1_bowl_water }
    object { tier1_falling_water }
    object { tier2_pillar }
    object { tier2_bowl }
    object { tier2_bowl_mosaic }
    object { tier2_bowl_water }
    object { tier2_falling_water }
  }
}
