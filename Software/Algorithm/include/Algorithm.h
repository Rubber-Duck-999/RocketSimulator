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
public:
	Interface() { createRocketSimulation(); };
	void receive_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData);
	void receive_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData);
	void receive_stateDataParameters(ROCKET_SIMULATOR::stateDataParameters& stateData);
	void send_algoData(ROCKET_SIMULATOR::algoData& algoData);


};

#endif
