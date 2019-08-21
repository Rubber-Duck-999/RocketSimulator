#include "land_algorithm.h"

void Land_Algorithm::CompareData()
{
    BOOST_LOG_TRIVIAL(info) << "Algo Run Function, Land_Algorithm.cc:5";
    double time_index = 0.0;
    bool end_loop = false;
    BOOST_LOG_TRIVIAL(debug) << "Algo data size: " << algo_data_.size();
    BOOST_LOG_TRIVIAL(debug) << "Map size: " << map_.size();
    /*for(unsigned int i = 0; i < algo_data_.size(); i++)
    {
        BOOST_LOG_TRIVIAL(debug) << "Algo values X Axis: " << algo_data_[i].position_axis_x_;
        BOOST_LOG_TRIVIAL(debug) << "Algo values Y Axis: " << algo_data_[i].position_axis_y_;
        BOOST_LOG_TRIVIAL(debug) << "Algo Data Direction: " << algo_data_[i].angle_of_direction_;
        BOOST_LOG_TRIVIAL(debug) << "Algo Data Time: " << algo_data_[i].time_milli_sec_;
    }*/

    if((algo_data_.size() && map_.size()) > 0)
    {
        std::map<unsigned int, double>::iterator local_iterator;
        unsigned int iterator_index_protector = 0;
        for(local_iterator = map_.begin(); iterator_index_protector < map_.size(); local_iterator++)
        {
            unsigned int index = 0;
            BOOST_LOG_TRIVIAL(debug) << "Map X Axis: " << local_iterator->first;
            while(index < algo_data_.size() && !end_loop)
            {
                if(0.00 >= (algo_data_[index].position_axis_x_ - local_iterator->first) < 1.00)
                {
                    /*if(algo_data_[index].position_axis_y_ <= local_iterator->second)
                    {
                        BOOST_LOG_TRIVIAL(debug) << "Algo Data X Axis: " << algo_data_[index].position_axis_x_;
                        BOOST_LOG_TRIVIAL(debug) << "Algo Data Y Axis: " << algo_data_[index].position_axis_y_;
                        BOOST_LOG_TRIVIAL(debug) << "Algo Data Direction: " << algo_data_[index].angle_of_direction_;
                        BOOST_LOG_TRIVIAL(debug) << "Algo Data Time: " << algo_data_[index].time_milli_sec_;
                        BOOST_LOG_TRIVIAL(debug) << "Map X Axis: " << local_iterator->first;
                        BOOST_LOG_TRIVIAL(debug) << "Map Y Axis: " << local_iterator->second;
                        BOOST_LOG_TRIVIAL(debug) << "We have crashed at Y axis: " << algo_data_[index].position_axis_y_ 
                        << " due to terrain height: " << local_iterator->second;
                        end_loop = true;
                    }*/
                }
                index++;
            }
            iterator_index_protector++;
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