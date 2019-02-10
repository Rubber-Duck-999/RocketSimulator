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
		//World(double density, double gravity);
		World() {};
		double getdensity() const;
		double getgravity() const;
	private:
		double _density = 0.0;
		//accelerationDueToGravity class variable
		double _gravity = 0.0;
		double EARTH_DENSITY = 1.22;
	    double EARTH_GRAVITY = 9.8;
};

#endif	/* WORLD_H */

