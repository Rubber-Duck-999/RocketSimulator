#include "Rocket.h"
#include "World.h"
#include "Thrust.h"
#include "dataStructure.h"
#include "buffer.h"

#ifndef INTERFACE_H
#define	INTERFACE_H


class Interface
{
	void createRocketSimulation();
	Rocket _rocket;
public:
	Interface()
	{
		createRocketSimulation();
	};
	void get_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData);
	void get_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData);
	void get_stateDataParameters(ROCKET_SIMULATOR::stateDataParameters& stateData);
	void set_algoData(ROCKET_SIMULATOR::algoData& algoData);
};

#endif
