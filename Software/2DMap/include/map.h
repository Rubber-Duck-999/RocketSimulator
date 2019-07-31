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
    std::vector<double> height_vector_;
    unsigned int index_;
    std::random_device random_obj_;
    unsigned int GetMapSize();
public:
    Map() 
    {
        index_ = 0;
        BOOST_LOG_TRIVIAL(info) << "Created Map Object";
    };
    ~Map() { };
    void CreateInitialMap();
    //
    bool GetMap(std::map<unsigned int, double>& map);
};

#endif
