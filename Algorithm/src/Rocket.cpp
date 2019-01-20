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

double Rocket::getmass()
{
    return _mass;
}

double Rocket::getdragAxisX()
{
    return _dragAxisX;
}

double Rocket::getdragAxisY()
{
    return _dragAxisY;
}

double Rocket::gethoriCrossSectArea()
{
    return _horiCrossSectArea;
}

double Rocket::getvertCrossSectArea()
{
    return _vertCrossSectArea;
}

double Rocket::getthrust()
{
    return _thrust;
}

double Rocket::getburnTime()
{
    return _burnTime;
}

double Rocket::getflowRate()
{
    return _flowRate;
}

double Rocket::getdistX()
{
    return _distX;
}

double Rocket::getdistY()
{
    return _distY;
}

void Rocket::setmass(double mass)
{
	_mass = mass;
}

void Rocket::setdragAxisX(double dragAxisX)
{
	_dragAxisX = dragAxisX;
}

void Rocket::setdragAxisY(double dragAxisY)
{
	_dragAxisY = dragAxisY;
}

void Rocket::sethoriCrossSectArea(double horiCrossSectArea)
{
	_horiCrossSectArea = horiCrossSectArea;
}

void Rocket::setvertCrossSectArea(double vertCrossSectArea)
{
	_vertCrossSectArea = vertCrossSectArea;
}

void Rocket::setthrust(double thrust)
{
	_thrust = thrust;
}

void Rocket::setburnTime(double burnTime)
{
	_burnTime = burnTime;
}

void Rocket::setflowRate(double flowRate)
{
	_flowRate = flowRate;
}

void Rocket::setdistX(double distX)
{
	_distX = distX;
}

void Rocket::setdistY(double distY)
{
	_distY = distY;
}
