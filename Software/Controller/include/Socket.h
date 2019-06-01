#include <arpa/inet.h>
#include <sstream>
#include <cstdlib>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdio.h>
#include <algorithm>
#include <memory>
#include "data_structure.h"
#include "logging.h"

#ifndef SOCKET_h
#define	SOCKET_h


class Socket
{
public:
	Socket() {};
    //
    ~Socket() { };
	//
    void NetworkReceive();
    void NetworkSend();
    void NetworkSetup();
    void NetworkShutdown();
    void Loop();
    rocket_simulator::StateDataParameters GetCurrentState()const { return current_state_; };
    void SetReceive(bool mode)
    {
        receive_mode_ = mode;
    }
    void MessageSet(const char* message);
    //
    void GetAlgorithmData(std::vector<double>& data);
private:
    //Functions
    void Split(std::string &message, std::string* subs);
	//	
	//Pointers for messages to be set
	const char* message_ptr_ = "ACK_";
    std::string state_configured_ = "State.CONFIGURED";
    std::string state_ready_ = "State.READY";
    std::string state_launch_ = "State.LAUNCH";
    std::string state_return_ = "State.RETURN";
    std::string state_shutdown_ = "State.SHUTDOWN";
    const int kConfigured = 1;
    const int kReady = 2;
    const int kLaunch = 3;
    const int kReturn = 4;
    const int kShutdown = 5;
    int expected_id_ = 101;
	//
    std::vector<std::string> messages_;
    std::vector<double> algorithm_data_;
    //
    bool receive_mode_ = false;
	bool run_ = false;
    //std::shared_ptr<std::string> my_message_ = new std::string;
	//Ports for socket setup
	const int kPort = 6111;
	//
    rocket_simulator::StateDataParameters current_state_;
    void SaveMessage(std::string message);
    void SendState(unsigned int state);
    int SizeOfMessageList();
	//Ports
	int network_socket_;
	//
    //Sockets server structure - 
	//required for creating the setup	
	struct sockaddr_in network_serv_;
	socklen_t network_len_;
};

#endif