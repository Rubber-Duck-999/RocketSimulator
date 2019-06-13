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
    rocket_simulator::StateDataParameters GetCurrentState() const { return current_state_; } ;
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
    rocket_simulator::StateDataParameters current_state_;
    //
    void SendState(unsigned int statedata);
    //
    void GetAlgorithmData(std::vector<rocket_simulator::AlgoData>& data);
    
    unsigned int id_;
    //Data Parameters
    rocket_simulator::RocketDataParameters rocket;
    rocket_simulator::TerrainMissionParameters world;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    //
};

#endif