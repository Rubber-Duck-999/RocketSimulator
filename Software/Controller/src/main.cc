#include "logging.h"
#include "socket.h"
#include "config_reader.h"
#include "algorithm.h"


int main()
{
    init_log();
    BOOST_LOG_TRIVIAL(debug) << "Start up of node";
    //
    Socket localsocket;
    localsocket.NetworkSetup();
    localsocket.SetReceiveOn(true);
    localsocket.NetworkReceive();
    localsocket.NetworkSend();
    localsocket.NetworkShutdown();
    //
    ConfigurationReader config;
    config.SetConfigValues();
    Algorithm algo;
    rocket_simulator::RocketDataParameters rocket_data;
    rocket_data.mass_ = 7.0;
    rocket_data.drag_axis_x_ = 20.0;
    rocket_data.drag_axis_y_ = 20.0;
    rocket_data.hori_cross_sect_area_ = 30.0;
    rocket_data.vert_cross_sect_area_ = 30.0;
    rocket_data.thrust_ = 100.0;
    rocket_data.burn_time_ = 200.0;
    rocket_data.flow_rate_ = 10.0;
    rocket_data.angle_of_launch_ = 75.0;
    rocket_simulator::TerrainMissionParameters terrain_data;
    terrain_data.density_ = 1.22;
    terrain_data.acceleration_due_to_gravity_ = 9.81;
    algo.GetRocketDataParameters(rocket_data);
    algo.GetTerrainMissionParameters(terrain_data);
    algo.CreateRocketSimulation();
    return 0;
}
 
