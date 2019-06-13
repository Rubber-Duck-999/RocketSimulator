/* 
 * File:   thrust.h
 * Author: Simon
 */
 
#include <stdio.h>
#include "rocket.h"
#include "world.h"
#include <math.h>
#include "data_structure.h"
#include "logging.h"
#include <fstream>

#ifndef THRUST_h
#define THRUST_h

class Thrust
{
private:
    Rocket rocket_;
    World world_;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    const double kPI = 3.14159265;
    int count_point_ = 0;
public:
    Thrust(Rocket &rocket_object, World &world_object, std::vector<rocket_simulator::AlgoData> &algo_data);
    void CoastFunction(double velocity_x_axis, double velocity_y_axis);
    void ThrustFunction();
};
#endif 
/* THRUST_h */

