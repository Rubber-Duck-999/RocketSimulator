#include "Land_Algorithm.h"

void Land_Algorithm::CompareData()
{
    BOOST_LOG_TRIVIAL(info) << "Algo Run Function, Land_Algorithm.cc:5";
    BOOST_LOG_TRIVIAL(debug) << "Algo data size: " << algo_data_.size();
    BOOST_LOG_TRIVIAL(debug) << "Map size: " << map_.size();

    if((algo_data_.size() && map_.size()) > 0)
    {
        std::map<unsigned int, double>::iterator local_iterator;
        unsigned int index = 0;
        for(local_iterator = map_.begin(); local_iterator != map_.end(); local_iterator++)
        {
            if(index == (algo_data_.size()-1))
            {
                BOOST_LOG_TRIVIAL(debug) << "Hit the end of the loop";
                BOOST_LOG_TRIVIAL(debug) << index;
                return;
            }
            double compare = (algo_data_[index].position_axis_x_ - local_iterator->first);
            if(0.00 >= compare && compare < 0.10)
            {
                if(algo_data_[index].position_axis_y_ <= local_iterator->second)
                {
                    BOOST_LOG_TRIVIAL(debug) << "CRASH!!!!";
                    BOOST_LOG_TRIVIAL(debug) << "Algo Data X Axis: " << algo_data_[index].position_axis_x_;
                    BOOST_LOG_TRIVIAL(debug) << "Algo Data Y Axis: " << algo_data_[index].position_axis_y_;
                    BOOST_LOG_TRIVIAL(debug) << "Algo Data Direction: " << algo_data_[index].angle_of_direction_;
                    BOOST_LOG_TRIVIAL(debug) << "Algo Data Time: " << algo_data_[index].time_milli_sec_;
                    BOOST_LOG_TRIVIAL(debug) << "Map X Axis: " << local_iterator->first;
                    BOOST_LOG_TRIVIAL(debug) << "Map Y Axis: " << local_iterator->second;
                    BOOST_LOG_TRIVIAL(debug) << "We have crashed at Y axis: " << algo_data_[index].position_axis_y_ 
                    << " due to terrain height: " << local_iterator->second;
                    x_axis_landing_point_ = local_iterator->first;
                    y_axis_landing_point_ = local_iterator->second;
                    rocket_crashed_ = true;
                    return;
                }
            }
            index++;
        }
    }
}

bool Land_Algorithm::RunAlgorithm()
{
    if(map_set_ && algo_data_set_)
    {
        CompareData();
        algo_finished_ = true;
    }
    return algo_finished_;
}

void Land_Algorithm::Set2DMap(std::map<unsigned int, double>& map)
{
    BOOST_LOG_TRIVIAL(debug) << "Setting 2D Map";
    map_ = map;
    map_set_ = true;
    BOOST_LOG_TRIVIAL(debug) << "Set 2D Map";
}

void Land_Algorithm::SetRocketAlgoData(std::vector<rocket_simulator::AlgoData>& algo_data)
{
    BOOST_LOG_TRIVIAL(debug) << "Setting Algo Data";
    algo_data_ = algo_data;
    algo_data_set_ = true;
    BOOST_LOG_TRIVIAL(debug) << "Set Algo Data";
}