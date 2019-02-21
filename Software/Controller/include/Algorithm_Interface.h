#include "dataStructure.h"
#include "buffer.h"
#include "Algorithm.h"

#ifndef ALGORITHM_INTERFACE_H
#define	ALGORITHM_INTERFACE_H

class Algorithm_Interface
{
public:
	Algorithm_Interface() {  };
	void send_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData);
	void send_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData);
	void send_stateDataParameters(ROCKET_SIMULATOR::stateDataParameters& stateData);
	void receive_algoData(ROCKET_SIMULATOR::algoData& algoData);
};



#endif
