#include "algorithm.h"


void Algorithm::GetRocketDataParameters(rocket_simulator::RocketDataParameters& rocket_data)
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

void Algorithm::GetTerrainMissionParameters(rocket_simulator::TerrainMissionParameters& terrain_data)
{
	rocket_simulator::TerrainMissionParameters* ptr_terrain = &terrain_data;
	if(ptr_terrain)
	{
        BOOST_LOG_TRIVIAL(info) << "Getting terrain data";
		World world_(terrain_data.density_, terrain_data.acceleration_due_to_gravity_);
		world_set_ = true;
	}
}

void Algorithm::SetAlgoData(rocket_simulator::AlgoData& algo_data)
{
	BOOST_LOG_TRIVIAL(info) << "Outputting algo data ";
	rocket_simulator::AlgoData* ptr_algo = &algo_data;
	if(ptr_algo)
	{
		algo_data = algo_data_;
        BOOST_LOG_TRIVIAL(info) << "Outputting algo data: ";
	}
}

bool Algorithm::CreateRocketSimulation()
{
	if(rocket_set_ && world_set_)
	{
        BOOST_LOG_TRIVIAL(info) << "Rocket and terrain is set ";
        BOOST_LOG_TRIVIAL(info) << "Calling algo ";
		Thrust thrust(rocket_, world_, algo_data_);
	}
    BOOST_LOG_TRIVIAL(info) << "Algo has finished ";
	return algo_finished_ = true;
}
