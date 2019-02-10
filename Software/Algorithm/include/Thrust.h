/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Thrust.h
 * Author: benwagley
 *
 * Created on May 10, 2016, 4:00 PM
 */
#include <stdio.h>
#include "Rocket.h"
#include "World.h"
#include <math.h>
#include <fstream>
#include <iostream>

#define PI 3.14159265

#ifndef THRUST_H
#define THRUST_H

class Thrust
{
	public:

		Thrust() {};

		Thrust(const Rocket &r, const World &b, double launchAngle) {};

		void coastFunction(double V, double Vt);
		void thrustFunction(double launchAngle);
		Rocket getrocketObject() const
		{
			return _r;
		}
		World getworldObject() const
		{
			return _b;
		}
	private:
		Rocket _r;
		World _b;
		int _countPoint = 0;
};
#endif /* THRUST_H */

