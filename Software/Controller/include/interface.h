#include "data_structure.h"
#include <string>
#include "logging.h"
#include "socket.h"
#include "config_reader.h"
#include "algorithm.h"
#include <boost/algorithm/string.hpp> 
#include <ctime>

#ifndef INTERFACE_h
#define	INTERFACE_h

class Interface
{
public:
    Interface();
    void shutdown()
    {
        local_socket_.NetworkShutdown();
    };
    
    void Receive();
private:
    Algorithm algo;
    //
    bool RunAlgo();
    //
    bool socket_receive_state_;  
    //
    Socket local_socket_;
    //
    ConfigurationReader config_;
    //
    std::vector<double> terrain_rocket_data_;
    //
    rocket_simulator::StateDataParameters current_state_;
    //
    void SendState(unsigned int statedata);
    //
    void SaveMessage(std::string message);
    //
    void GetAlgorithmData(std::vector<double>& data);
    
    unsigned int id_;
    //Data Parameters
    rocket_simulator::RocketDataParameters rocket;
    rocket_simulator::TerrainMissionParameters world;
    //
};

#endif