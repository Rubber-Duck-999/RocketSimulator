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
#include "Algorithm.h"


void Interface::get_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData)
{
	ROCKET_SIMULATOR::rocketDataParameters* ptrRocket = &rocketData;
	if(ptrRocket)
	{
		std::cout << "Before Change = " << rocketData.mass << std::endl;
		Rocket tempRocket(rocketData.mass, rocketData.dragAxisX, rocketData.dragAxisY,
				rocketData.horiCrossSectArea, rocketData.vertCrossSectArea,
				rocketData.thrust, rocketData.burnTime, rocketData.flowRate);
		_rocket = tempRocket;
		std::cout << "After Change = " << _rocket.getmass() << std::endl;
	}
}

void Interface::get_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData)
{
	ROCKET_SIMULATOR::terrainMissionParameters* ptrTerrain = &terrainData;
	if(ptrTerrain)
	{
		terrainData.density = 0.0;
	}
}

void Interface::get_stateDataParameters(ROCKET_SIMULATOR::stateDataParameters& stateData)
{
	//readFromBuffer(stateData);
	std::cout << "State currently = " << std::endl;
	//stateData = ROCKET_SIMULATOR::stateDataParameters.NON_CONFIGURED;
}

void Interface::set_algoData(ROCKET_SIMULATOR::algoData& _algoData)
{
	std::cout << "_algoData" << std::endl;
	//ROCKET_SIMULATOR::algoData* algoData = *_algoData;
	//if(algoData)
	//{
	//	_algoData = algoData;
	//}
}

void Interface::createRocketSimulation()
{
    //Rocket (mass, drag x, drag y, area x, area y, newtons of thrust , burn time , flow rate);
    Rocket rocket(80, .3, .3, 1, 1, 100, 50, 20);
    /*World ( density of air,  acceleration due to gravity) if this is left blank then it creates a world
        equivalent to earth. */
    World world;
    // Creates array to handle output, first value is distance traveled on  x, then dist on y, then seconds of travel.
    //runs thrust function passing it the rocket, the world it is in, and the angle of launch
    Thrust thrust(rocket, world, 85.0);
    //printf("Time Taken: %f\n", rocket.gettimeTaken());
}
