#include <iostream>
#include "logging.h"
#include "data_structure.h"
#include "interface.h"
#include "config_reader.h"
#include "graphics.h"
#include "map.h"

int main()
{
    Map my_map;
    my_map.CreateInitialMap();
    std::map<unsigned int, double> map;
    bool map_correct = my_map.GetMap(map);
    BOOST_LOG_TRIVIAL(debug) << "Map is valid: " << map_correct << ", Creation Size: " << map.size();
    ConfigurationReader cfg;
    cfg.SetConfigValues();
    Interface out;
    //out.Loop();
    Graphics screen;
    screen.RunRocket(out.GetLaunchAngle());
    out.Shutdown();  
    return 0;
}
 
