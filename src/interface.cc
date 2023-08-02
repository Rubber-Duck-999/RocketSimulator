#include "interface.h"

Interface::Interface()
{
    id_ = 101;
    world.density_ = 0.0;
    world.acceleration_due_to_gravity_ = 0.0;
    rocket.mass_ = 0.0;
    rocket.drag_axis_x_ = 0.0;
    rocket.drag_axis_y_ = 0.0;
    rocket.hori_cross_sect_area_ = 0.0;
    rocket.vert_cross_sect_area_ = 0.0;
    rocket.thrust_ = 0.0;
    rocket.burn_time_ = 0.0;
    rocket.flow_rate_ = 0.0;
    rocket.angle_of_launch_ = 0.0;
}

std::map<double, double> Interface::GetCoordinates() 
{ 
    return coordinates_; 
}

void Interface::RunSimulation()
{
    if (RunAlgo()) {
        Map my_map(rocket_simulator::kMinHeight, rocket_simulator::kMaxHeight, rocket_simulator::kMaxXAxisLength);
        my_map.CreateInitialMap();
        std::map<unsigned int, double> map;
        bool map_correct = my_map.GetMap(map);
        BOOST_LOG_TRIVIAL(debug) << "Map is valid: " << map_correct << ", Creation Size: " << map.size();
        simulation_.Set2DMap(map);
        simulation_.SetRocketAlgoData(algo_.algo_data_);
        simulation_.RunAlgorithm();
        coordinates_.clear();
        coordinates_ = simulation_.GetCoordinates();
    }
}


bool Interface::RunAlgo()
{
    BOOST_LOG_TRIVIAL(debug) << "Starting call of Algo";
    algo_.GetRocketDataParameters(rocket);
    algo_.GetTerrainMissionParameters(world);
    if(algo_.CreateRocketSimulation())
    {
        GetAlgorithmData();
        return true;
    }
    else
    {
        return false;
    }
}


void Interface::GetAlgorithmData()
{
    BOOST_LOG_TRIVIAL(debug) << "Passing algo data";
    BOOST_LOG_TRIVIAL(debug) << "Size: " << algo_.algo_data_.size();
    algo_data_ = algo_.algo_data_;
    BOOST_LOG_TRIVIAL(debug) << "Size After: " << algo_data_.size();
}