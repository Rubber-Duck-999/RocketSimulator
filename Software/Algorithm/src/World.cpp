/* 
 * File:   World.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:24 AM
 */

#include "World.h"


//World::World(double density /*Density of air*/, double gravity /*Gravitational acceleration*/)
//{
//    _density = density;
//    _gravity = gravity;
//}

double World::getdensity() const
{
    return _density;
}

double World::getgravity() const
{
    return _gravity;
}