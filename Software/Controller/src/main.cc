#include <iostream>
#include "logging.h"
#include "data_structure.h"
#include "interface.h"
#include "config_reader.h"
#include "map.h"

int main()
{
    ConfigurationReader cfg;
    cfg.SetConfigValues();
    Interface out;
    out.Loop();
    out.Shutdown();  
    return 0;
}
 
