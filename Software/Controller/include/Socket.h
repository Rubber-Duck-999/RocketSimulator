#include <arpa/inet.h>
#include <iostream>
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
#include "logging.h"

#ifndef SOCKET_h
#define	SOCKET_h

class Socket
{
public:
	Socket() 
    { 
        std::shared_ptr<std::string> my_message_ = std::make_shared<std::string>();
    };
    //
    ~Socket() { };
	//
    void NetworkReceive();
    void NetworkSend();
    void NetworkSetup();
    void NetworkShutdown();
    void SetReceiveOn(bool mode)
    {
        receive_mode_ = mode;
    }
    //
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
	//
    std::vector<std::string> messages_;
    //
    bool receive_mode_ = false;
	bool run_ = false;
    //std::shared_ptr<std::string> my_message_ = new std::string;
	//Ports for socket setup
	const int kPort = 6111;
	//
    void SaveMessage(std::string message);
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