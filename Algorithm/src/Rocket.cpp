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
}

const double Rocket::getmass()
{
    return _mass;
}

const double Rocket::getdragAxisX()
{
    return _dragAxisX;
}

const double Rocket::getdragAxisY()
{
    return _dragAxisY;
}

const double Rocket::gethoriCrossSectArea()
{
    return _horiCrossSectArea;
}

const double Rocket::getvertCrossSectArea()
{
    return _vertCrossSectArea;
}

const double Rocket::getthrust()
{
    return _thrust;
}

const double Rocket::getburnTime()
{
    return _burnTime;
}

const double Rocket::getflowRate()
{
    return _flowRate;
}

const double Rocket::getdistX()
{
    return _distX;
}

const double Rocket::getdistY()
{
    return _distY;
}

const float Rocket::gettimeTaken()
{
	return _time;
}

void Rocket::setmass(const double mass)
{
	_mass = mass;
}

void Rocket::setdragAxisX(const double dragAxisX)
{
	_dragAxisX = dragAxisX;
}

void Rocket::setdragAxisY(const double dragAxisY)
{
	_dragAxisY = dragAxisY;
}

void Rocket::sethoriCrossSectArea(const double horiCrossSectArea)
{
	_horiCrossSectArea = horiCrossSectArea;
}

void Rocket::setvertCrossSectArea(const double vertCrossSectArea)
{
	_vertCrossSectArea = vertCrossSectArea;
}

void Rocket::setthrust(const double thrust)
{
	_thrust = thrust;
}

void Rocket::setburnTime(const double burnTime)
{
	_burnTime = burnTime;
}

void Rocket::setflowRate(const double flowRate)
{
	_flowRate = flowRate;
}

void Rocket::setdistX(const double distX)
{
	_distX = distX;
}

void Rocket::setdistY(const double distY)
{
	_distY = distY;
}

void Rocket::settimeTaken(const float time)
{
	_time = time;
}
