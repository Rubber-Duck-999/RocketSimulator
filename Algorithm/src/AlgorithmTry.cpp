//============================================================================
// Name        : AlgorithmTry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Rocket.h"
#include "World.h"
#include "Thrust.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv)
{
	cout << "Welcome to the Algorithm" << endl;
    //Rocket (mass, drag x, drag y, area x, area y, newtons of thrust , burn time , flow rate);
    Rocket rocket(80, .3, .3, 1, 1, 100, 50, 20);
    /*World ( density of air,  acceleration due to gravity) if this is left blank then it creates a world
        equivalent to earth. */
    World world;
    // Creates array to handle output, first value is distance traveled on  x, then dist on y, then seconds of travel.
    //runs thrust function passing it the rocket, the world it is in, and the angle of launch
    thrust(rocket, world, 85);
    printf("Time Taken: %f\n", rocket.gettimeTaken());
    //plots in GNUPlot
    plot();
    return 0;
}
