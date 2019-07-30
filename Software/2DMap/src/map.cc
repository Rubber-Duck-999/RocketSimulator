#include "map.h"

void Map::CreateInitialMap()
{
    unsigned int x_axis_start = 0;
    unsigned int x_axis = 0;
    double height = 0;

    srand(time(0));
    unsigned int random;

    while(x_axis <= rocket_simulator::kMaxXAxisLength)
    {
        random = (rand() % 10) + 1;
        BOOST_LOG_TRIVIAL(debug) << "Random number: " << random;
    }

    initial_terrain_map_.insert(std::pair<unsigned int, double>(x_axis, height));
}