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
#include "dataStructure.h"
#include <fstream>
#include <iostream>

#ifndef THRUST_H
#define THRUST_H

class Thrust
{
	public:
		Thrust(Rocket &r, World &b, double launchAngle, ROCKET_SIMULATOR::algoData algoData);

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
		bool openFile();
	private:
		Rocket _r;
		World  _b;
		FILE*  _dataFile;
		const char* _fileName = "data.dat";
		ROCKET_SIMULATOR::algoData _algoData;
		const double PI = 3.14159265;
		int _countPoint = 0;
};
#endif /* THRUST_H */

