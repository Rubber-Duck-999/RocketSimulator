#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include "data_structure.h"
#include "logging.h"

#ifndef MAP_h
#define	MAP_h


class Map
{
private:
    std::map<int, double> initial_terrain_map_;
public:
    Map() {};
    void CreateInitialMap();
};

#endif
