#include "flight_algorithm.h"

void Flight_Algorithm::GetRocketDataParameters(rocket_simulator::RocketDataParameters& rocket_data)
{
    rocket_simulator::RocketDataParameters* ptr_rocket = &rocket_data;
    if(ptr_rocket)
    {
        BOOST_LOG_TRIVIAL(info) << "Getting rocket data";
        BOOST_LOG_TRIVIAL(info) << "Rocket mass: " << rocket_data.mass_;
        Rocket temp_rocket(rocket_data.mass_, rocket_data.drag_axis_x_, rocket_data.drag_axis_y_,
                rocket_data.hori_cross_sect_area_, rocket_data.vert_cross_sect_area_,
                rocket_data.thrust_, rocket_data.burn_time_, rocket_data.flow_rate_, rocket_data.angle_of_launch_);
        rocket_ = temp_rocket;
        rocket_set_ = true;
        BOOST_LOG_TRIVIAL(info) << "After Change = " << rocket_.GetMass();
    }
}

void Flight_Algorithm::GetTerrainMissionParameters(rocket_simulator::TerrainMissionParameters& terrain_data)
{
    rocket_simulator::TerrainMissionParameters* ptr_terrain = &terrain_data;
    if(ptr_terrain)
    {
        BOOST_LOG_TRIVIAL(info) << "Getting terrain data";
        BOOST_LOG_TRIVIAL(info) << "Density: " << terrain_data.density_;
        World temp_world_(terrain_data.density_, terrain_data.acceleration_due_to_gravity_);
        world_ = temp_world_;
        if(temp_world_.GetDensity() == world_.GetDensity())
        {
            world_set_ = true;
        }
    }
}

bool Flight_Algorithm::CreateRocketSimulation()
{
    if(rocket_set_ && world_set_)
    {
        BOOST_LOG_TRIVIAL(info) << "Rocket and terrain is set ";
        BOOST_LOG_TRIVIAL(info) << "Calling algo ";
        Thrust thrust(rocket_, world_, algo_data_);
        BOOST_LOG_TRIVIAL(info) << "Algo has finished ";
        algo_finished_ = true;
        WriteToFile();
        return algo_finished_;
    }
    else
    {
        algo_finished_ = false;
        return algo_finished_;
    }
}

bool Flight_Algorithm::WriteToFile()
{
    std::ofstream myfile;
    myfile.open ("data.csv");
    myfile << "Algorithm Data.\n";
    myfile << "a,b,c,\n";
    for(int i = 0; i < algo_data_.size(); i++)
    {
        myfile << algo_data_[i].position_axis_x_ << "," << algo_data_[i].position_axis_y_ << "," <<
                algo_data_[i].angle_of_direction_ << "," << algo_data_[i].time_milli_sec_ << "\n";
    }
    myfile.close();  
    return true;
}