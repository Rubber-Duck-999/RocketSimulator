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

double coast(Rocket r, World b, double V /*Velocity*/,
        double Vt /*Direction in Degrees */, double h /*height*/);
void thrust(Rocket &r, World b, double lt);


#endif /* THRUST_H */

