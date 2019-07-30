#include <iostream>
#include "logging.h"
#include "data_structure.h"
#include "interface.h"
#include "config_reader.h"
#include "graphics.h"

int main()
{
    Graphics screen;
    ConfigurationReader cfg;
    cfg.SetConfigValues();
    Interface out;
    out.Loop();
    out.Shutdown();
    time_t nowLater = time(0);
    // convert now to string form
    char* dtLater = ctime(&nowLater);
    BOOST_LOG_TRIVIAL(info) << "The local date and time is: " << dtLater << endl;     
    return 0;
}
 
