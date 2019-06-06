#include "logging.h"

#ifndef ROCKET_h
#define	ROCKET_h

class Rocket
{
private:
    double mass_;
    double drag_axis_x_;
    double drag_axis_y_;
    double hori_cross_sect_area_;
    double vert_cross_sect_area_;
    double thurst_;
    double burn_time_;
    double flow_rate_;
    double distance_x_;
    double distance_y_;
    double time_;
    double launch_angle_;
public:
    Rocket() {};

    //Constructor for class Rocket
    Rocket(double mass, double drag_axis_x, double drag_axis_y,
        double hori_cross_sect_area, double vert_cross_sect_area,
        double thrust, double burn_time, double flow_rate, double launch_angle);
    //
    ~Rocket() {};
    //Get functions for class member variables
    double GetMass() const { return mass_; }
    double GetDragAxisX() const { return drag_axis_x_; }
    double GetDragAxisY() const { return drag_axis_y_; }
    double GetHoriCrossSectArea() const { return hori_cross_sect_area_; }
    double GetVertCrossSectArea() const { return vert_cross_sect_area_; }
    double GetThrust() const { return thurst_; }
    double GetBurnTime() const { return burn_time_; }
    double GetFlowRate() const { return flow_rate_; }
    double GetLaunchAngle() const { return launch_angle_; }
    double GetDistanceX() const { return distance_x_; }
    double GetDistanceY() const { return distance_y_; }
    double GetTimeTaken() const { return time_; }

    //Set functions for class member variables
    void SetMass(const double &mass)
    {
        mass_ = mass;
    }
    void SetDragAxisX(const double &drag_axis_x)
    {
        drag_axis_x_ = drag_axis_x;
    }
    void SetDragAxisY(const double &drag_axis_y)
    {
        drag_axis_y_ = drag_axis_y;
    }
    void SetHoriCrossSectArea(const double &hori_cross_sect_area)
    {
        hori_cross_sect_area_ = hori_cross_sect_area;
    }
    void SetVertCrossSectArea(const double &vert_cross_sect_area)
    {
        vert_cross_sect_area_ = vert_cross_sect_area;
    }
    void SetThrust(const double &thrust)
    {
        thurst_ = thrust;
    }
    void SetBurnTime(const double &burn_time)
    {
        burn_time_ = burn_time;
    }
    void SetFlowRate(const double &flow_rate)
    {
        flow_rate_ = flow_rate;
    }
    void SetDistanceX(const double &distance_x)
    {
        distance_x_ = distance_x;
    }
    void SetDistanceY(const double &distance_y)
    {
        distance_y_ = distance_y;
    }
    void SetTimeTaken(const double &time)
    {
        time_ = time;
    }
    void SetLaunchAngle(const double &launch_angle)
    {
        launch_angle_ = launch_angle;
    }

};

#endif	/* ROCKET_H */

