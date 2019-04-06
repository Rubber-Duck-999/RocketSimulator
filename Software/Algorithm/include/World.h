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
	   World() {};
		//World(double density, double gravity);
		World(double density, double gravity)
		{
			_density = density;
			_gravity = gravity;
		}
		double getdensity() const;
		double getgravity() const;
	private:
		double _density;
		double _gravity;
		double EARTH_DENSITY = 1.22;
	    double EARTH_GRAVITY = 9.8;
};

#endif	/* WORLD_H */

