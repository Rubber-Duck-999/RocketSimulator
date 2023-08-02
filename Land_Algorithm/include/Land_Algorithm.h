#include <cstdlib>
#include "data_structure.h"
#include "logging.h"
#include <fstream>

#ifndef LAND_ALGORITHM_h
#define	LAND_ALGORITHM_h


class Land_Algorithm
{
private:
    std::map<unsigned int, double> map_;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    bool map_set_;
    bool algo_data_set_;
    bool algo_finished_;
    bool WriteToFile();
    void CompareData();
    std::map<double, double> coordinates_;
public:
    Land_Algorithm() 
    {
        algo_finished_ = false;
        map_set_ = false;
        algo_data_set_ = false;
    };
    bool RunAlgorithm();
    void Set2DMap(std::map<unsigned int, double>& map);
    void SetRocketAlgoData(std::vector<rocket_simulator::AlgoData>& algo_data);
    std::map<double, double> GetCoordinates();
};

#endif
