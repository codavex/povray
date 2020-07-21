// File: coins.inc
// Desc: model coin

#version 3.7;

#include "metals.inc"

#macro coin(coin_texture, coin_scale)
  union {
    object {
      cylinder { <0,0,0> <0, .001,0> 0.01 }
      texture {
        coin_texture
        normal {
          bump_map { png "bump_images/heads.png" once bump_size 2.0 }
          rotate x*90
          translate <-.5,0,-.5>
          scale <1.34, 1, 1>
          scale <0.015,1,0.015>
        }
      }
    }
    object {
      cylinder { <0,0,0> <0, .001,0> 0.01 }
      texture {
        coin_texture
        normal {
          bump_map { png "bump_images/tails.png" once bump_size 2.0 }
          rotate x*90
          translate <-.5,0,-.5>
          scale <0.015,1,0.015>
          rotate y*180
        }
      }
      rotate x*180
    }
    scale <coin_scale, 1, coin_scale>
  }
#end

#macro coin_ridges(coin_texture, coin_radius)
  #local shift=0;
  #local num_ridges=40;
  #local ridge_rotation=360/num_ridges;
  #while (shift < num_ridges)
    object {
      cylinder { <0,-.001,0> <0,.001,0> .0005 }
      scale <.2, 1, 1.1>
      translate x*coin_radius
      rotate y*shift*ridge_rotation
      texture { coin_texture }
    }
    #declare shift=shift+1;
  #end
#end

#declare silver_coin = object {
  union {
    coin(T_Silver_5A, 1)
    coin_ridges(T_Silver_5A, 0.01)
  }
}

#declare copper_coin = object {
  union {
    coin(T_Copper_5A, .8)
    coin_ridges(T_Copper_5A, 0.008)
  }
}

#declare silver_and_gold_coin = object {
  union {
    coin(T_Gold_5A, 0.9)
    object {
      difference {
        object { cylinder { <0,-.001,0> <0, .001,0> 0.012 } }
        object { cylinder { <0,-.002,0> <0, .002,0> 0.009 } }
      }
      texture { T_Silver_5A }
    }
    coin_ridges(T_Silver_5A, 0.012)
  }
}
