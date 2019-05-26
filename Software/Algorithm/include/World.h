#include "logging.h"

#ifndef WORLD_h
#define	WORLD_h

const double kEarthDensity = 1.22;
const double kEarthGravity = 9.81;

class World
{
public:
    World() {};
    ~World() {};
    //World(double density, double gravity);
    World(double density, double gravity)
    {
        density_ = density;
        gravity_ = gravity;
    }
    double GetDensity() const;
    double GetGravity() const;
private:
    double density_;
    double gravity_;
};

#endif
/* WORLD_h */

