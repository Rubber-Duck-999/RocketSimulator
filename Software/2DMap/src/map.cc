#include "map.h"

void Map::CreateInitialMap()
{
    std::uniform_real_distribution<> distr_height_(rocket_simulator::kMinHeight, rocket_simulator::kMaxHeight);
    std::mt19937 eng(random_obj_());
    while(index_ <= rocket_simulator::kMaxXAxisLength)
    {
        double loop_random = distr_height_(eng);
        BOOST_LOG_TRIVIAL(trace) << "Random number Index: " << index_ << " Value: " << loop_random;
        height_vector_.push_back(loop_random);
        index_ = index_ + 1;
    }
    index_ = 1;
    BOOST_LOG_TRIVIAL(trace) << "Beginning reassign";
    while(index_ < (height_vector_.size() - 1))
    {
        if(index_ <= rocket_simulator::kLaunchLength)
        {
            height_vector_[index_] = 0.0;
            //BOOST_LOG_TRIVIAL(trace) << "Assign Height Index: " << index_ << ", Value: " << height_vector_[index_];
        }
        else
        {
            height_vector_[index_] = (height_vector_[index_ - 1] + 
                                height_vector_[index_] + 
                                height_vector_[index_ + 1]) / 3;
        }
        index_ = index_ + 1;
        BOOST_LOG_TRIVIAL(trace) << "Height Index: " << index_ << ", Value: " << height_vector_[index_];
    }
    for(unsigned int i = 0; i < (height_vector_.size() - 1); i++)
    {
        BOOST_LOG_TRIVIAL(debug) << "Reworked Height Index: " << i << ", Value: " << height_vector_[i];
        initial_terrain_map_.insert(std::pair<unsigned int, double>(i, height_vector_[i]));
    }
}

unsigned int Map::GetMapSize()
{
    return initial_terrain_map_.size();
}


//GetMap returns true if the map is invalid to merge
bool Map::GetMap(std::map<unsigned int, double>& map)
{
    if(initial_terrain_map_.size() > 0)
    {
        map.merge(initial_terrain_map_);
        return true;
    }
    else
    {
        return false;
    }
}