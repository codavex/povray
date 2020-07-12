// Persistence of Vision Ray Tracer Scene Description File
// File: well.inc
// Vers: 3.5
// Desc: well macro
// Date: Mar 05
// Auth: David Cox

//#declare pigment_seed=seed(0);
//#declare brick_jitter=seed(1);
                  
#macro Well(brick_seed, pigment_seed, height, outer_rad, inner_rad, layers, num_bricks, brick_offset, height_variance, length_variance, above_ground, parapet)
  #declare pigment_jitter=seed(pigment_seed);
  #declare brick_jitter=seed(brick_seed);
  #declare well_rad = inner_rad + (outer_rad-inner_rad)/2;
  #declare current_layer=0;
  #declare current_height=0;
  #declare current_offset=0;
  #declare temp=0;
  #declare brick_height=height/layers;
  #declare brick_heights=array[layers];
  
  #while(current_layer<layers-1)
    #declare brick_heights[current_layer]=brick_height+(rand(brick_jitter)-.5)*brick_height*height_variance;
    #declare temp = temp + brick_heights[current_layer]; 
    #declare current_layer=current_layer+1;
  #end
  #declare brick_heights[current_layer]=height-temp;  

  /*#declare well_brick = object {
    difference {
      object { cylinder {  0*y,  brick_height*0.95*y,  outer_rad } }
      object { cylinder { -1*y,  brick_height*1.02*y,  inner_rad } }
      object { plane { z, 0 } }
      object { plane { -z, 0 } rotate y*(360/num_bricks)*0.97 }            
    }
  }*/
  #macro well_brick(height, rot)
    object {
      difference {
        object { cylinder {  0*y,  height*0.97*y,  outer_rad } }
        object { cylinder { -1*y,  height*1.02*y,  inner_rad } }
        object { plane { z, 0 } }
        object { plane { -z, 0 } rotate y*rot*0.97 }            
      }
    }
  #end

  /*#declare well_brick = object {
    isosurface {
      function { f_rounded_box(x,y,z, 0.2, 1, 1, 1) - (f_noise3d(x * 5, y * 5, z * 5)*.05) }
    }   
    scale <1, .5, 1>
    translate y*.5
    scale <(outer_rad-inner_rad)/2, brick_height, (outer_rad*3.14)/num_bricks>
    translate <well_rad, 0, 0>
  } */
  
  union {
    object {
      difference {
        cylinder {  0*y,  (height-brick_heights[layers-1]-0.004)*y,  outer_rad*0.99 }
        cylinder { -1*y,  height*1.02*y,  inner_rad*1.02 }      
      }
      texture { pigment { color Gray85 } }
    }

    #declare current_layer=0;
    #while(current_layer<layers)
      #declare current_brick = 0;
      #declare temp = 0;
      #declare brick_angles=array[num_bricks];
      #while(current_brick<num_bricks-1)
        #declare brick_angles[current_brick]=(360/num_bricks)+(rand(brick_jitter)-.5)*(360/num_bricks)*length_variance;
        #declare temp = temp + brick_angles[current_brick];
        #declare current_brick=current_brick+1;
      #end
      #declare brick_angles[current_brick]=360-temp;
      
      #declare temp = 0;
      #declare current_brick = 0;
      #declare brick_offset_jitter = 30*rand(brick_jitter);
      #while(current_brick < num_bricks)
        object {
          #declare brickPigment = (0.2*rand(pigment_seed))+0.8;
          well_brick(brick_heights[current_layer], brick_angles[current_brick])
          //scale <1, brick_heights[current_layer]/brick_height, 1>
          rotate y*(temp+current_offset)
          translate current_height*y
          texture {
            pigment { rgb <brickPigment,brickPigment,brickPigment> }
            normal { granite scale .5 }
            translate <rand(pigment_seed),rand(pigment_seed),rand(pigment_seed)>
          }
        }
        #declare temp = temp + brick_angles[current_brick];
        #if(current_layer = layers - 1)
          #if(parapet=true)
            #declare current_brick = current_brick + 1;                                
            #declare temp = temp + brick_angles[current_brick];
            #declare current_brick = current_brick + 1;                   
          #end
        #else
          #declare current_brick = current_brick + 1;                                
        #end
      #end
      #declare current_height = current_height + brick_heights[current_layer];
      #declare current_layer = current_layer + 1;
      #declare current_offset = current_offset + brick_offset+brick_offset_jitter;
    #end
    translate y*(-height)*(1-above_ground)
  }
#end


