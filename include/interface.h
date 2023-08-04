#include "data_structure.h"
#include <string>
#include <unistd.h>
#include "Flight_Algorithm.h"
#include "Land_Algorithm.h"
#include "map.h"
#include <boost/algorithm/string.hpp> 
#include <ctime>


#ifndef INTERFACE_h
#define	INTERFACE_h

class Interface
{
public:
    Interface();
    //
    ~Interface() { };
    //
    void RunSimulation();
    //
    std::map<double, double> GetCoordinates();
    //
    std::list<double> GetAngles();
private:
    //
    Flight_Algorithm algo_;
    //
    Land_Algorithm simulation_;
    //
    bool RunAlgo();
    //
    void GetAlgorithmData();
    //
    unsigned int id_;
    //Data Parameters
    rocket_simulator::RocketDataParameters rocket;
    rocket_simulator::TerrainMissionParameters world;
    rocket_simulator::LauncherMissionParameters launcher;
    std::map<double, double> coordinates_;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    std::list<double> angles_;
    //
};

#endif