#include "logging.h"
#include "interface.h"

int main()
{
    init_log();
    Interface out;
    out.Loop();
    out.Shutdown();  
    return 0;
}
 
