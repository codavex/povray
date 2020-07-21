// File: gravity.inc
// Desc: animate a falling object using gravity

#version 3.7;

#declare gravity_rand = seed (1975);

#macro gravity_trajectory(falling_object, start_height, end_height)
  #declare falling_distance = start_height - end_height;
  #declare falling_time = sqrt(falling_distance/(.5*9.8));
  #declare falling_clock = clock+(falling_time*rand(gravity_rand));
  #while(falling_clock > falling_time)
    #declare falling_clock = falling_clock - falling_time;
  #end
  #declare fall = .5*9.8*falling_clock*falling_clock; // .5*G*t_squared
  object {
    falling_object
    translate <0, start_height-fall, 0>
  }
#end

