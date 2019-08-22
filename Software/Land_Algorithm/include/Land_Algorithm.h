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
    bool rocket_crashed_;
    bool WriteToFile();
    void CompareData();
    unsigned int x_axis_landing_point_;
    double y_axis_landing_point_;
public:
    Land_Algorithm() 
    {
        algo_finished_ = false;
        map_set_ = false;
        algo_data_set_ = false;
        rocket_crashed_ = false;
        x_axis_landing_point_ = 0;
        y_axis_landing_point_ = 0.0;
    };
    bool RunAlgorithm();
    const bool DidTheRocketCrash() const
    {
        return rocket_crashed_;
    };
    unsigned int GetXAxisLandingPoint() const
    {
        return x_axis_landing_point_;
    }
    double GetYAxisLandingPoint() const
    {
        return y_axis_landing_point_;
    }
    void Set2DMap(std::map<unsigned int, double>& map);
    void SetRocketAlgoData(std::vector<rocket_simulator::AlgoData>& algo_data);
};

#endif
