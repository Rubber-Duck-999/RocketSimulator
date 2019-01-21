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
}

double Rocket::getmass() const
{
    return _mass;
}

double Rocket::getdragAxisX() const
{
    return _dragAxisX;
}

double Rocket::getdragAxisY() const
{
    return _dragAxisY;
}

double Rocket::gethoriCrossSectArea() const
{
    return _horiCrossSectArea;
}

double Rocket::getvertCrossSectArea() const
{
    return _vertCrossSectArea;
}

double Rocket::getthrust() const
{
    return _thrust;
}

double Rocket::getburnTime() const
{
    return _burnTime;
}

double Rocket::getflowRate() const
{
    return _flowRate;
}

double Rocket::getdistX() const
{
    return _distX;
}

double Rocket::getdistY() const
{
    return _distY;
}

float Rocket::gettimeTaken() const
{
	return _time;
}

void Rocket::setmass(const double &mass)
{
	_mass = mass;
}

void Rocket::setdragAxisX(const double &dragAxisX)
{
	_dragAxisX = dragAxisX;
}

void Rocket::setdragAxisY(const double &dragAxisY)
{
	_dragAxisY = dragAxisY;
}

void Rocket::sethoriCrossSectArea(const double &horiCrossSectArea)
{
	_horiCrossSectArea = horiCrossSectArea;
}

void Rocket::setvertCrossSectArea(const double &vertCrossSectArea)
{
	_vertCrossSectArea = vertCrossSectArea;
}

void Rocket::setthrust(const double &thrust)
{
	_thrust = thrust;
}

void Rocket::setburnTime(const double &burnTime)
{
	_burnTime = burnTime;
}

void Rocket::setflowRate(const double &flowRate)
{
	_flowRate = flowRate;
}

void Rocket::setdistX(const double &distX)
{
	_distX = distX;
}

void Rocket::setdistY(const double &distY)
{
	_distY = distY;
}

void Rocket::settimeTaken(const float &time)
{
	_time = time;
}
