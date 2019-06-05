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
    Interface()  //(bool receive_state):socket_receive_state_(receive_state)
    { 
        local_socket_.NetworkSetup();
        current_state_.state = rocket_simulator::kNON_CONFIGURED;
    };
    void shutdown()
    {
        local_socket_.NetworkShutdown();
    };
    
    void Receive();
private:
    bool socket_receive_state_;  
    Socket local_socket_;
    ConfigurationReader config_;
    std::vector<double> terrain_rocket_data_;
    rocket_simulator::StateDataParameters current_state_;
    void SendState(unsigned int statedata);
    void SaveMessage(std::string message);
    void GetAlgorithmData(std::vector<double>& data);
};

#endif