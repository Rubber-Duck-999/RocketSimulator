#include "Rocket.h"
#include "World.h"
#include "Thrust.h"
#include "dataStructure.h"

#ifndef ALGORITHM_H
#define	ALGORITHM_H


class Algorithm
{
	Rocket _rocket;
	World _world;
	ROCKET_SIMULATOR::algoData _algoData;
	double _angleOfLaunch;
	bool _rocketSet = false;
	bool _worldSet = false;
	bool _algoFinished = false;
public:
	Algorithm() {};
	bool createRocketSimulation();
	void get_rocketDataParameters(ROCKET_SIMULATOR::rocketDataParameters& rocketData);
	void get_terrainMissionParameters(ROCKET_SIMULATOR::terrainMissionParameters& terrainData);
	void set_algoData(ROCKET_SIMULATOR::algoData& algoData);
	bool getAlgoFinished() { return _algoFinished; };
};

#endif
