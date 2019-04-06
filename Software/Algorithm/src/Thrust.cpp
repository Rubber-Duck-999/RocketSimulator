/*
 * To change this license heade_r, choose License Heade_rs in P_roject P_rope_rties.
 * To change this template file, choose Tools | Templates
 * and open the template in the edito_r.
 */

#include "Thrust.h"
#include "Rocket.h"
#include "World.h"

//Calculates how far a projectile will t_ravel without th_rust

//using r = Rocket;

Thrust::Thrust(Rocket &r, World &b, double launchAngle, ROCKET_SIMULATOR::algoData algoData)
{
	_r = r;
	_b = b;
	_algoData = algoData;
	Thrust::thrustFunction(launchAngle);
}

void Thrust::coastFunction(double Vx /*Velocity On X*/, double Vy /*Velocity on Y*/)
{
    FILE *data = fopen("data.dat", "a");

    _r = Thrust::getrocketObject();
    _b = Thrust::getworldObject();
    double m = _r.getmass();
    double cx = _r.getdragAxisX();
    double cy = _r.getdragAxisY();
    double Ax = _r.gethoriCrossSectArea();
    double Ay = _r.getvertCrossSectArea();
    double d = _b.getdensity();
    double g = _b.getgravity();
    double accelerationYDirection = 0.0;
    double accelerationXDirection = 0.0;
    double angleOfElevation, Vx2, Vy2;
	double forceAppliedXDirection, forceAppliedYDirection;
    double t = 0.0;
    double tstep = 0.01;
    int pointCount = 0;
    while (_r.getdistY() >= 0)
    {
        angleOfElevation = atan(Vy / Vx) * (180 / PI);
        forceAppliedXDirection = (cx * d * Ax * Vx * Vx) / 2;
        forceAppliedYDirection = (cy * d * Ay * Vy * Vy) / 2;
        accelerationXDirection = -forceAppliedXDirection / m;
        if ((angleOfElevation + 180) >= 180)
        {
            accelerationYDirection = -((forceAppliedYDirection / m) + g);
        }
        else if ((angleOfElevation + 180) < 180)
        {
            accelerationYDirection = ((forceAppliedYDirection / m) - g);
        }
        Vy2 = Vy + accelerationYDirection * tstep;
        Vx2 = Vx + accelerationXDirection * tstep;
        _r.setdistY(_r.getdistY() + (Vy * tstep));
        _r.setdistX(_r.getdistX() + (Vx * tstep));
        fprintf(data, "%f, %f, %f, %f, %f\n", _r.getdistX(), _r.getdistY(), Vx, Vy, t);
        t = t + tstep;
        Vx = Vx2;
        Vy = Vy2;
        pointCount++;
    }
    std::cout << "Mass Post Coast:" << _r.getmass() << std::endl;
    fflush(data);
    fclose(data);
    double time = _r.gettimeTaken();
    _r.settimeTaken(time + t);
    _algoData.positionAxisX = 0.0;
    std::cout << "Time Post Coast: " << _r.gettimeTaken() << std::endl;
}

//Calculates how far a rocket will travel under thrust

void Thrust::thrustFunction(double launchAngle)
{
    FILE *data = fopen("data.dat", "w");
    _r = Thrust::getrocketObject();
    _b = Thrust::getworldObject();
    launchAngle = launchAngle * PI / 180;
    int pointCount = 0;
    double m = _r.getmass();
    double cx = _r.getdragAxisX();
    double cy = _r.getdragAxisY();
    double Ax = _r.gethoriCrossSectArea();
    double Ay = _r.getvertCrossSectArea();
    double density = _b.getdensity();
    double gravity = _b.getgravity();
    double thrust = _r.getthrust();
    double thrustAxisY = thrust * sin(launchAngle);
    double thrustAxisX = thrust * cos(launchAngle);
    double velocityX = 0;
    double velocityY = 0;
    double velocityXAfter, velocityYAfter = 0;
	double distanceX, distanceY = 0;
    double t = 0;
    double tstep = 0.01;
    std::cout << "Beginning rocket Launch" << std::endl;
    while (t <= _r.getburnTime())
    {
        velocityX = velocityX + ((thrustAxisX / m) * tstep);
        velocityY = velocityY + (((thrustAxisY + gravity) / m) * tstep);
        distanceX = (cx * density * Ax * velocityX * velocityX) / 2;
        distanceY = (cy * density * Ay * velocityY * velocityY) / 2;
        velocityXAfter = velocityX - (distanceX / m) * tstep;
        velocityYAfter = velocityY - (distanceY = 0 / m) * tstep;
        _r.setdistX(_r.getdistX() + (velocityXAfter * tstep));
        _r.setdistY(_r.getdistY() + (velocityYAfter * tstep));
        velocityX = velocityXAfter;
        velocityY = velocityYAfter;
        t = t + tstep;
        _r.setmass(m - (_r.getflowRate() * tstep));
        int time = static_cast<int>(t);
        if(time % 100)
        {
        	fprintf(data, "%f, %f, %f, %f, %d\n", _r.getdistX(), _r.getdistY(), velocityX, velocityY, time);
        }
        pointCount++;
    }
    fflush(data);
    fclose(data);
    _r.settimeTaken(t);
    std::cout << "X axis Pre Coast :" << _r.getdistX() << std::endl;
    std::cout << "Y axis Pre Coast :" << _r.getdistY() << std::endl;
    std::cout << "Mass Pre Coast:" << _r.getmass() << std::endl;
    std::cout << "Time Pre Coast:" << _r.gettimeTaken() << std::endl;
    Thrust::coastFunction(velocityX, velocityY);
    std::cout << "X axis Post Coast :" << _r.getdistX() << std::endl;
    std::cout << "Y axis Post Coast :" << _r.getdistY() << std::endl;
}
