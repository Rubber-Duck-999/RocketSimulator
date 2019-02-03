#include "Rocket.h"
#include "World.h"
#include "Thrust.h"
#include "dataStructure.h"

#ifndef INTERFACE_H
#define	INTERFACE_H


class Interface
{
	void receive_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters* rocketData);
	void receive_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters* terrainData);
	void receive_stateDataParameters(ROCKET_SIMULATOR::stateDataParameters* stateData);
	ROCKET_SIMULATOR::algoData send_algoData(ROCKET_SIMULATOR::algoData& algoData);
	void createRocketSimulation();
public:
	Interface();


};

#endif
