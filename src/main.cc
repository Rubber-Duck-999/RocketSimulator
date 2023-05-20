#include "logging.h"
#include "interface.h"
#include "init.h"
#include "engine.h"

int main()
{
    init_log();
    Interface out;
    if (InitAllegro(60, 800, 600)) {
        BOOST_LOG_TRIVIAL(info) << "main.cc:11 We have set up allegro correctly";
    } else {
        BOOST_LOG_TRIVIAL(info) << "main.cc:13 We have set up allegro incorrectly";
    }
    InitGame();
    out.RunSimulation();
    return 0;
}
 
