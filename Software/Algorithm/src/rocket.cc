/* 
 * File:   rocket.cc
 * Author: Simon
 */

#include "rocket.h"

Rocket::Rocket(double mass, double drag_axis_x, double drag_axis_y,
               double hori_cross_sect_area, double vert_cross_sect_area,
			   double thrust, double burn_time, double flow_rate)
{
    BOOST_LOG_TRIVIAL(info) << "Creating rocket";
	mass_ = mass,
	drag_axis_x_ = drag_axis_x;
	drag_axis_y_ = drag_axis_y;
	hori_cross_sect_area_ = hori_cross_sect_area;
	vert_cross_sect_area_ = vert_cross_sect_area;
    thurst_ = thrust;
    burn_time_ = burn_time;
    flow_rate_ = flow_rate;
    distance_x_ = 0;
    distance_y_ = 0;
};

