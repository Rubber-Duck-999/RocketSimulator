#include "thrust.h"

//Calculates how far a projectile will tr_avel without thr_ust

Thrust::Thrust(Rocket &rocket_object, World &world_object, rocket_simulator::AlgoData algo_data)
{
    BOOST_LOG_TRIVIAL(info) << "Creating thrust ";
	rocket_ = rocket_object;
	world_ = world_object;
	algo_data_ = algo_data;
	Thrust::ThrustFunction();
}


void Thrust::CoastFunction(double velocity_x_axis, double velocity_y_axis)
{
    //FILE* data_file_ = fopen(file_name_, "a");
    rocket_ = Thrust::GetRocketObject();
    world_ = Thrust::GetWorldObject();
    double mass = rocket_.GetMass();
    double drag_axis_x = rocket_.GetDragAxisX();
    double drag_axis_y = rocket_.GetDragAxisY();
    double hori_cross_sect_area = rocket_.GetHoriCrossSectArea();
    double vert_cross_sect_area = rocket_.GetVertCrossSectArea();
    double density = world_.GetDensity();
    double gravity = world_.GetGravity();
    double acceleration_y_direction = 0.0;
    double acceleration_x_direction = 0.0;
    double angle_of_elevation, velocity_x_axis_post, velocity_y_axis_post, force_x_direction, force_y_direction;
    double t_start = 0.0;
    double t_step = 0.01;
    while (rocket_.GetDistanceY() >= 0)
    {
        BOOST_LOG_TRIVIAL(debug) << "Inside coast";
        angle_of_elevation = atan(velocity_y_axis / velocity_x_axis) * (180 / kPI);
        force_x_direction = (drag_axis_x * density * hori_cross_sect_area * velocity_x_axis * velocity_x_axis) / 2;
        force_y_direction = (drag_axis_y * density * vert_cross_sect_area * velocity_y_axis * velocity_y_axis) / 2;
        acceleration_x_direction = -force_x_direction / mass;
        if ((angle_of_elevation + 180) >= 180)
        {
            acceleration_y_direction = -((force_y_direction / mass) + gravity);
        }
        else if ((angle_of_elevation + 180) < 180)
        {
            acceleration_y_direction = ((force_y_direction / mass) - gravity);
        }
        velocity_y_axis_post = velocity_y_axis + acceleration_y_direction * t_step;
        velocity_x_axis_post = velocity_x_axis + acceleration_x_direction * t_step;
        rocket_.SetDistanceY(rocket_.GetDistanceY() + (velocity_y_axis * t_step));
        rocket_.SetDistanceX(rocket_.GetDistanceX() + (velocity_x_axis * t_step));
        fprintf(data_file_, "%f, %f, %f, %f, %f\n", rocket_.GetDistanceX(), rocket_.GetDistanceY(), velocity_x_axis, velocity_y_axis, t_start);
        t_start = t_start + t_step;
        velocity_x_axis = velocity_x_axis_post;
        velocity_y_axis = velocity_y_axis_post;
    }
    BOOST_LOG_TRIVIAL(info) << "Mass Post Coast:" << rocket_.GetMass();
    fflush(data_file_);
    fclose(data_file_);
    double time = rocket_.GetTimeTaken();
    rocket_.SetTimeTaken(time + t_start);
    algo_data_.position_axis_x = 0.0;
    BOOST_LOG_TRIVIAL(info) << "Time Post Coast: " << rocket_.GetTimeTaken();
}

//Calculates how far a rocket will travel under thrust

void Thrust::ThrustFunction()
{
    BOOST_LOG_TRIVIAL(info) << "Running thrust function ";
    FILE* data_file_ = fopen(file_name_, "w");
    rocket_ = Thrust::GetRocketObject();
    world_ = Thrust::GetWorldObject();
    double launch_angle = rocket_.GetLaunchAngle() * kPI / 180;
    double m = rocket_.GetMass();
    double drag_axis_x = rocket_.GetDragAxisX();
    double drag_axis_y = rocket_.GetDragAxisY();
    double hori_cross_sect_area = rocket_.GetHoriCrossSectArea();
    double vert_cross_sect_area = rocket_.GetVertCrossSectArea();
    double density = world_.GetDensity();
    double gravity = world_.GetGravity();
    double thrust = rocket_.GetThrust();
    double thrust_axis_y = thrust * sin(launch_angle);
    double thrust_axis_x = thrust * cos(launch_angle);
    double velocity_x = 0.0;
    double velocity_y = 0.0;
    double velocity_x_after, velocity_y_after = 0.0;
	double distance_x, distance_y = 0.0;
    double t_start = 0.0;
    double t_step = 0.01;
    BOOST_LOG_TRIVIAL(info) << "Beginning Rocket Launch";
    while (t_start < rocket_.GetBurnTime())
    {
        velocity_x = velocity_x + ((thrust_axis_x / m) * t_step);
        velocity_y = velocity_y + (((thrust_axis_y + gravity) / m) * t_step);
        distance_x = (drag_axis_x * density * hori_cross_sect_area * velocity_x * velocity_x) / 2;
        distance_y = (drag_axis_y * density * vert_cross_sect_area * velocity_y * velocity_y) / 2;
        velocity_x_after = velocity_x - (distance_x / m) * t_step;
        velocity_y_after = velocity_y - (distance_y = 0 / m) * t_step;
        rocket_.SetDistanceX(rocket_.GetDistanceX() + (velocity_x_after * t_step));
        rocket_.SetDistanceY(rocket_.GetDistanceY() + (velocity_y_after * t_step));
        velocity_x = velocity_x_after;
        velocity_y = velocity_y_after;
        t_start = t_start + t_step;
        rocket_.SetMass(m - (rocket_.GetFlowRate() * t_step));
        fprintf(data_file_, "%f, %f, %f, %f, %d \n", rocket_.GetDistanceX(), rocket_.GetDistanceY(), velocity_x, velocity_y, t_start);
    }
    //fflush(data_file_);
    //fclose(data_file_);
    rocket_.SetTimeTaken(t_start);
    BOOST_LOG_TRIVIAL(info) << "X axis Pre Coast :" << rocket_.GetDistanceX();
    BOOST_LOG_TRIVIAL(info) << "Y axis Pre Coast :" << rocket_.GetDistanceY();
    BOOST_LOG_TRIVIAL(info) << "Mass Pre Coast:" << rocket_.GetMass();
    BOOST_LOG_TRIVIAL(info) << "Time Pre Coast:" << rocket_.GetTimeTaken();
    CoastFunction(velocity_x, velocity_y);
    BOOST_LOG_TRIVIAL(info) << "X axis Post Coast :" << rocket_.GetDistanceX();
    BOOST_LOG_TRIVIAL(info) << "Y axis Post Coast :" << rocket_.GetDistanceY();
}
