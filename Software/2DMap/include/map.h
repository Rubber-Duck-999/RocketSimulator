#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <random>
#include <ctime>
#include "data_structure.h"
#include "logging.h"
#include <map>

#ifndef MAP_h
#define	MAP_h


class Map
{
private:
    std::map<unsigned int, double> initial_terrain_map_;
    double min_range_;
    double max_range_;
    unsigned int max_x_axis_;
    std::vector<double> height_vector_;
    unsigned int index_;
    std::random_device random_obj_;
    unsigned int GetMapSize();
public:
    Map(double min_range, double max_range, unsigned int max_entries) 
    {
        index_ = 0;
        min_range_ = min_range;
        max_range_ = max_range;
        max_x_axis_ = max_entries;
        BOOST_LOG_TRIVIAL(info) << "Created Map Object";
    };
    //
    void CreateInitialMap();
    //
    bool GetMap(std::map<unsigned int, double>& map);
    //
    void SetTerrainRanges(double min_range, double max_range)
    {
        min_range_ = min_range;
        max_range_ = max_range;
    }
    //
    void SetMaxSize(unsigned int max_size)
    {
        max_x_axis_ = max_size;
    }
};

#endif
