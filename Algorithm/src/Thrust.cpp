/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Thrust.h"

//Calculates how far a projectile will travel without thrust

double * coast(Rocket r, World b, double Vx /*Velocity On X*/, double Vy /*Velocity on Y*/) {
    FILE *data = fopen("data.dat", "a");

    static double outCoast[3];
    double m = r.getmass();
    double cx = r.getdragAxisX();
    double cy = r.getdragAxisY();
    double Ax = r.gethoriCrossSectArea();
    double Ay = r.getvertCrossSectArea();
    double d = b.getdensity();
    double g = b.getgravity();
    double Vt, Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double t = 0;
    double tstep = .01;

    while (r.getdistY() >= 0) {
        Vt = atan(Vy / Vx) * (180 / PI);
        Dx = (cx * d * Ax * Vx * Vx) / 2;
        Dy = (cy * d * Ay * Vy * Vy) / 2;
        ax = -Dx / m;
        if ((Vt + 180) >= 180) {
            ay = -((Dy / m) + 9.8);
        } else if ((Vt + 180) < 180) {
            ay = ((Dy / m) - 9.8);
        }
        Vy2 = Vy + ay * tstep;
        Vx2 = Vx + ax * tstep;
        r.setdistY(r.getdistY() + (Vy * tstep));
        r.setdistX(r.getdistX() + (Vx * tstep));
        fprintf(data, "%f %f\n", r.getdistX(), r.getdistY());
        t += tstep;
        Vx = Vx2;
        Vy = Vy2;

    }
    fflush(data);
    fclose(data);
    outCoast[0] = r.getdistX();
    outCoast[1] = r.getdistY();
    outCoast[2] = t;

    return outCoast;
}

//Calculates how far a rocket will travel under thrust

double * thrust(Rocket r, World b, double lt)
{
    FILE *data = fopen("data.dat", "w");
    
    lt = lt * PI / 180;
    int pointCount = 0;
    double outThrust[3];
    double *outC;
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
    double Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double distx = 0;
    double disty = 0;
    double t = 0;
    double tstep = .01;
    std::cout << "Beginning Rocket Launch" << std::endl;
    while (t <= r.getburnTime())
    {
        Vx = Vx + ((Tx / m) * tstep);
        Vy = Vy + (((Ty + 9.8) / m) * tstep);
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
        fprintf(data, "%f %f\n", r.getdistX(), r.getdistY());
        std::cout << "X axis value : " << r.getdistX() << std::endl;
        std::cout << "Y axis value : " << r.getdistY() << std::endl;
        std::cout << "Time so far : " << t << std::endl;
        pointCount++;
    }
    fflush(data);
    fclose(data);
    outC = coast(r, b, Vx, Vy);
    outThrust[0] = r.getdistX();
    outThrust[1] = r.getdistY();
    outThrust[2] = t + outC[2];
    std::cout << "Time I believe" << outThrust[2] << std::endl;

    return outThrust;
}

