#include "data_structure.h"
#include <string>
#include "logging.h"
#include <boost/algorithm/string.hpp> 
#include <ctime>
#include <SFML/Graphics.hpp>
#include "ship.h"

#ifndef Graphics_h
#define	Graphics_h

class Graphics
{
public:
    Graphics() {};
    void RunRocket(double launch_angle);
};

#endif