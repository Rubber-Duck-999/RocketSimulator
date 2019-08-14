#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "data_structure.h"
#include "logging.h"
#include <fstream>

#ifndef LAND_ALGORITHM_h
#define	LAND_ALGORITHM_h


class Land_Algorithm
{
private:
    bool algo_set_;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    bool algo_finished_;
    bool WriteToFile();
public:
    Land_Algorithm() 
    {
        algo_finished_ = false;
    };
    const bool RunAlgorithm() { return algo_finished_; };
    void Set2DMap(std::map<unsigned int, double>& map);
    void SetRocketAlgoData(std::vector<rocket_simulator::AlgoData>& algo_data);
};

#endif
