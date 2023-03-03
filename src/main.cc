#include "logging.h"
#include "interface.h"
#include "simulator.h"


int main()
{
    init_log();
    Interface out;
    create();
    out.Loop();
    out.Shutdown();
    return 0;
}
 
