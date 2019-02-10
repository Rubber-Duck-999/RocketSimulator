/* 
 * File:   Rocket.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:10 AM
 */

#include "Rocket.h"

Rocket::Rocket(double mass, double dragAxisX, double dragAxisY,
               double horiCrossSectArea, double vertCrossSectArea,
			   double thrust, double burnTime, double flowRate)
{
	_mass = mass,
	_dragAxisX = dragAxisX;
	_dragAxisY = dragAxisY;
	_horiCrossSectArea = horiCrossSectArea;
	_vertCrossSectArea = vertCrossSectArea;
    _thrust = thrust;
    _burnTime = burnTime;
    _flowRate = flowRate;
    _distX = 0;
    _distY = 0;
};

