/* 
 * File:   thrust.h
 * Author: Simon
 */
 
#include <stdio.h>
#include "rocket.h"
#include "world.h"
#include <math.h>
#include "data_structure.h"
#include "logging.h"
#include <fstream>
#include <iostream>

#ifndef THRUST_h
#define THRUST_h

class Thrust
{
	public:
		Thrust(Rocket &rocket_object, World &world_object, double launch_angle, rocket_simulator::AlgoData algo_data);

		void CoastFunction(double velocity_x_axis, double velocity_y_axis);
		void ThrustFunction(double launch_angle);
        
		Rocket GetRocketObject() const
		{
			return rocket_;
		}
		World GetWorldObject() const
		{
			return world_;
		}
        
		bool OpenFile();
	private:
		Rocket rocket_;
		World  world_;
		FILE*  data_file_;
		const char* file_name_ = "data.dat";
		rocket_simulator::AlgoData algo_data_;
		const double kPI = 3.14159265;
		int count_point_ = 0;
};
#endif 
/* THRUST_h */

