/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Thrust.h"

//Calculates how far a projectile will travel without thrust

double coast(Rocket &r, World b, double Vx /*Velocity On X*/, double Vy /*Velocity on Y*/)
{
    FILE *data = fopen("data.csv", "a");

    double m = r.getmass();
    double cx = r.getdragAxisX();
    double cy = r.getdragAxisY();
    double Ax = r.gethoriCrossSectArea();
    double Ay = r.getvertCrossSectArea();
    double d = b.getdensity();
    double g = b.getgravity();
    double accelerationYDirection = 0.0;
    double accelerationXDirection = 0.0;
    double angleOfElevation, Vx2, Vy2;
	double forceAppliedXDirection, forceAppliedYDirection;
    double t = 0;
    double tstep = 0.01;
    double x;
    while (r.getdistY() >= 0)
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
        r.setdistY(r.getdistY() + (Vy * tstep));
        r.setdistX(r.getdistX() + (Vx * tstep));
        x = std::fmod (t, 1.0);
        if(x > 0.99)
        {
        	fprintf(data, "%f %f %f %f %f\n", r.getdistX(), r.getdistY(), Vx, Vy, t);
        }
        t += tstep;
        Vx = Vx2;
        Vy = Vy2;
    }
    std::cout << "Mass Post Coast:" << r.getmass() << std::endl;
    fflush(data);
    fclose(data);
    return t;
}

//Calculates how far a rocket will travel under thrust

void thrust(Rocket &r, World b, double lt)
{
    FILE *data = fopen("data.csv", "w");
    
    lt = lt * PI / 180;
    int pointCount = 0;
    double outThrust;
    double outC = 0.0;
    double m = r.getmass();
    double cx = r.getdragAxisX();
    double cy = r.getdragAxisY();
    double Ax = r.gethoriCrossSectArea();
    double Ay = r.getvertCrossSectArea();
    double d = b.getdensity();
    double g = b.getgravity();
    double T = r.getthrust();
    double Ty = T * sin(lt);
    double Tx = T * cos(lt);
    double Vx = 0;
    double Vy = 0;
    double ax, ay, Vx2, Vy2, Dx, Dy;
    double distx = 0;
    double disty = 0;
    double t = 0;
    double tstep = 0.01;
    double x;
    std::cout << "Beginning Rocket Launch" << std::endl;
    while (t <= r.getburnTime())
    {
        Vx = Vx + ((Tx / m) * tstep);
        Vy = Vy + (((Ty + g) / m) * tstep);
        Dx = (cx * d * Ax * Vx * Vx) / 2;
        Dy = (cy * d * Ay * Vy * Vy) / 2;
        Vx2 = Vx - (Dx / m) * tstep;
        Vy2 = Vy - (Dx / m) * tstep;
        r.setdistX(r.gethoriCrossSectArea() + (Vx2 * tstep));
        r.setdistY(r.getvertCrossSectArea() + (Vy2 * tstep));
        Vx = Vx2;
        Vy = Vy2;
        t = t + tstep;
        r.setmass(m + r.getflowRate() / tstep);
        x = std::fmod (t, 1.0);
        if(x > 0.99)
        {
        	fprintf(data, "%f %f %f %f %f\n", r.getdistX(), r.getdistY(), Vx, Vy, t);
        }
        pointCount++;
    }
    fflush(data);
    fclose(data);
    std::cout << "X axis Pre Coast :" << r.getdistX() << std::endl;
    std::cout << "Y axis Pre Coast :" << r.getdistY() << std::endl;
    std::cout << "Mass Pre Coast:" << r.getmass() << std::endl;
    outC = coast(r, b, Vx, Vy);
    outThrust = t + outC;
    std::cout << "X axis Post Coast :" << r.getdistX() << std::endl;
    std::cout << "Y axis Post Coast :" << r.getdistY() << std::endl;
    std::cout << "Time I believe :" << outThrust << std::endl;
}

