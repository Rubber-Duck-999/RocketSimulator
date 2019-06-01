#include <boost/lockfree/spsc_queue.hpp>
#include "logging.h"
#include "socket.h"
#include "config_reader.h"
#include "algorithm.h"
#include "data_structure.h"
#include <thread>
#include <ctime>

int main()
{
    init_log();
    BOOST_LOG_TRIVIAL(info) << "Start up of node";
    //
    Socket localsocket;
    localsocket.NetworkSetup();
    localsocket.SetReceive(true);
    localsocket.Loop();
    ConfigurationReader config;
    std::vector<double> data;
    localsocket.GetAlgorithmData(data);
    /*for(unsigned int x = 0; x < data.size(); x++)
    {
        BOOST_LOG_TRIVIAL(info) << "Consume: " << data[x];
    }*/
    localsocket.NetworkShutdown();  
    config.SetConfigValues();
    BOOST_LOG_TRIVIAL(info) << "After the thread the state is: " << localsocket.GetCurrentState().state;
    //
    time_t now = time(0);
    // convert now to string form
    char* dt = ctime(&now);
    BOOST_LOG_TRIVIAL(info) << "The local date and time is: " << dt << endl;
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
    time_t nowLater = time(0);
    // convert now to string form
    char* dtLater = ctime(&nowLater);
    BOOST_LOG_TRIVIAL(info) << "The local date and time is: " << dtLater << endl;    
    return 0;
}
 
