#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Rocket.h"
#include "World.h"
#include "Thrust.h"
#include "data_structure.h"
#include "logging.h"
#include <fstream>

#ifndef FLIGHT_ALGORITHM_h
#define	FLIGHT_ALGORITHM_h


class Flight_Algorithm
{
private:
    Rocket rocket_;
    World world_;
    bool WriteToFile();
    bool rocket_set_ = false;
    bool world_set_ = false;
    bool algo_finished_ = false;
public:
    Flight_Algorithm() {};
    bool IsRocketSet() const { return rocket_set_; };
    bool IsWorldSet() const { return world_set_; };
    bool CreateRocketSimulation();
    void GetRocketDataParameters(rocket_simulator::RocketDataParameters& rocket_data);
    void GetTerrainMissionParameters(rocket_simulator::TerrainMissionParameters& terrain_data);
    bool GetAlgoFinished() { return algo_finished_; };
    std::vector<rocket_simulator::AlgoData> algo_data_;
};

#endif
