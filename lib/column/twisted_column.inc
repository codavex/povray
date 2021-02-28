// File: twisted_column.inc

#version 3.7;

#declare  Hexagon =
 intersection
  {plane {x, 1}  /* Rotate 90 in z axis to stand up */
   plane {x, 1 rotate <0, 060, 0>}
   plane {x, 1 rotate <0, 120, 0>}
   plane {x, 1 rotate <0, 180, 0>}
   plane {x, 1 rotate <0, 240, 0>}
   plane {x, 1 rotate <0, 300, 0>}
   plane { y, 1}
   plane {-y, 0}

   bounded_by {sphere{0, 1.5}}
  }

#macro TwistedColumn(colRadius, colHeight, iter)
  #declare smallHeight=colHeight/iter;
  #declare rot=180/iter;
  #declare col=0;
  object {
    union {
      #while (col<iter)
        object {
          Hexagon
          scale <colRadius,smallHeight,colRadius>
          rotate y*col*rot
          translate y*col*smallHeight
        }                        
        #declare col=col+1;
      #end
    }
  }
#end                                        

