#include "data_structure.h"
#include <string>
#include "logging.h"
#include <boost/algorithm/string.hpp> 
#include <ctime>
#include <SFML/Graphics.hpp>

#ifndef Graphics_h
#define	Graphics_h

class Graphics
{
public:
    Graphics();
private:
    void RunWindow();
};

#endif