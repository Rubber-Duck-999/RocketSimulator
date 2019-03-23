#include "dataStructure.h"
#include "buffer.h"
#include "Algorithm.h"

#ifndef ALGORITHM_INTERFACE_H
#define	ALGORITHM_INTERFACE_H

class Algorithm_Interface
{
	Interface algo;
public:
	Algorithm_Interface() { Interface algo; };
	void send_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData)
	{
		algo.get_rocketDataParameters(rocketData);
	}
	void send_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData)
	{
		algo.get_terrainMissionParameters(terrainData);
	}
	void receive_algoData(ROCKET_SIMULATOR::algoData& algoData)
	{
		algo.set_algoData(algoData);
	}
};

#endif
