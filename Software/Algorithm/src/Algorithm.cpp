#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Algorithm.h"


void Algorithm::get_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData)
{
	ROCKET_SIMULATOR::rocketDataParameters* ptrRocket = &rocketData;
	if(ptrRocket)
	{
		std::cout << "Before Change = " << rocketData.mass << std::endl;
		Rocket tempRocket(rocketData.mass, rocketData.dragAxisX, rocketData.dragAxisY,
				rocketData.horiCrossSectArea, rocketData.vertCrossSectArea,
				rocketData.thrust, rocketData.burnTime, rocketData.flowRate);
		_rocket = tempRocket;
		_angleOfLaunch = rocketData.angleOfLaunch;
		_rocketSet = true;
		std::cout << "After Change = " << _rocket.getmass() << std::endl;
	}
}

void Algorithm::get_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData)
{
	ROCKET_SIMULATOR::terrainMissionParameters* ptrTerrain = &terrainData;
	if(ptrTerrain)
	{
		World _world(terrainData.density, terrainData.accelerationDueToGravity);
		_worldSet = true;
	}
}

void Algorithm::set_algoData(ROCKET_SIMULATOR::algoData& algoData)
{
	std::cout << "_algoData" << std::endl;
	ROCKET_SIMULATOR::algoData* ptrAlgo = &algoData;
	if(ptrAlgo)
	{
		algoData = _algoData;
	}
}

bool Algorithm::createRocketSimulation()
{
	if(_rocketSet && _worldSet)
	{
		Thrust thrust(_rocket, _world, _angleOfLaunch, _algoData);
	}
	return _algoFinished = true;
}
