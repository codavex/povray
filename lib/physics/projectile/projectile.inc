// File: projectile.inc
// Desc: animate a projectile with initial speed, launch angle and gravity

#version 3.7;

#include "physics/physics.inc"

#declare projectile_rand = seed (1975);

#macro projectile_trajectory(projectile, height, launch_angle, launch_velocity)
  #declare launch_radians = radians(launch_angle);
  #declare x_launch_velocity = launch_velocity * cos(launch_radians);
  #declare y_launch_velocity = launch_velocity * sin(launch_radians);
  #declare flight_time = (y_launch_velocity + sqrt((y_launch_velocity*y_launch_velocity) + 2*gravity*height))/gravity;
  #declare projectile_clock = clock+(flight_time*rand(projectile_rand));
  #while(projectile_clock > flight_time)
    #declare projectile_clock = projectile_clock - flight_time;
  #end
  #declare x_disp = x_launch_velocity*projectile_clock;
  #declare y_disp = height + y_launch_velocity*projectile_clock - .5*gravity*projectile_clock*projectile_clock; // .5*G*t_squared
  object {
    projectile
    translate <x_disp, y_disp, 0>
  }
#end

