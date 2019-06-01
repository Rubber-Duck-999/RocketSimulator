#include "data_structure.h"
#include "logging.h"
#include "socket.h"
#include "config_reader.h"
#include "algorithm.h"
#include <ctime>

#ifndef INTERFACE_h
#define	INTERFACE_h

class Interface
{
public:
    Interface(bool receive_state):socket_receive_state_(receive_state)
    { 
    
    };
private:
    bool socket_receive_state_;  
    Socket local_socket_;
    ConfigurationReader config_;
    std::vector<double> terrain_rocket_data_;
    rocket_simulator::StateDataParameters current_state_;
    
};

#endif