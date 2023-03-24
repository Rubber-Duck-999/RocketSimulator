#include "logging.h"
#include "interface.h"
#include "init.h"


int main()
{
    init_log();
    Interface out;
    InitAllegro();
    out.RunSimulation();
    return 0;
}
 
