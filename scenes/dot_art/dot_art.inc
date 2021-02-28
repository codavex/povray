// Persistence of Vision Ray Tracer Scene Description File
// File: dotart.inc
// Vers: 3.5
// Desc: Aboriginal Dot Art
// Date: Feb 06
// Auth: Dave Cox
// ToDo: randomise rad and position

#version 3.5;

#macro dot_art(length, height, min_rad, max_rad, spacer, pigment_function)
  #local a=0;
  #local indent=0;      
  #local spacer=1.5*max_rad;
  #local spacer_sqrd=spacer*spacer;
  #while(a<length)
    #local indent=mod(indent+spacer,spacer*2);
    #local b=indent;
    #while(b<height)
      #local rad=max_rad;
      object {
        sphere { <a, b, 0>, min_rad }
        texture {
          finish { ambient 1 }
          pigment {
            color <pigment_function(a, b, 0).red,
                   pigment_function(a, b, 0).green,
                   pigment_function(a, b, 0).blue>
          }
        }
      }
      #local b=b+(2*spacer);
    #end
  #local a=a+sqrt((4*spacer_sqrd)-spacer_sqrd);
  #end
#end
