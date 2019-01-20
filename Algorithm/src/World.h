/* 
 * File:   World.h
 * Author: student
 *
 * Created on May 5, 2016, 11:24 AM
 */

#ifndef WORLD_H
#define	WORLD_H

class World
{
	public:
		World(double density, double gravity);
		World();
		double getdensity();
		double getgravity();
	private:
		double _density;
		//accelerationDueToGravity class variable
		double _gravity;
		const double EARTH_DENSITY = 1.223;
		const double EARTH_GRAVITY = 9.8;
};

#endif	/* WORLD_H */

