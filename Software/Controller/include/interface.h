#include "data_structure.h"
#include "start_up_process.h"
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
    //
    void Shutdown()
    {
        local_socket_.NetworkShutdown();
    };
    //
    void Loop();
    //
    rocket_simulator::StateDataParameters GetCurrentState() const { return current_state_; } ;
    //
    void Receive(std::string message);
    //
    unsigned int GetIdNumber() const { return id_; };
    //
private:
    //
    bool pilot_set_;
    //
    bool RunSimulation();
    //
    bool SetCorrect(int number);
    //
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
    void SetPilots(unsigned int pilot);
    //
    void GetAlgorithmData(std::vector<rocket_simulator::AlgoData>& data);
    //
    unsigned int id_;
    //Data Parameters
    rocket_simulator::RocketDataParameters rocket;
    rocket_simulator::TerrainMissionParameters world;
    rocket_simulator::LauncherMissionParameters launcher;
    std::vector<rocket_simulator::AlgoData> algo_data_;
    //
};

#endif