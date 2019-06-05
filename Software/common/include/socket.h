#include <arpa/inet.h>
#include <sstream>
#include <cstdlib>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdio.h>
#include <algorithm>
#include <memory>
#include "data_structure.h"
//#include "logging.h"

#ifndef SOCKET_h
#define	SOCKET_h


class Socket
{
public:
	Socket() 
    {
        receive_mode_ = false;
    };
    //
    ~Socket() { };
	//
    std::string NetworkReceive();
    void NetworkSend(std::string message);
    void NetworkSetup();
    void NetworkShutdown();
    void SetReceive(bool mode)
    {
        receive_mode_ = mode;
    }
    //
private:
    //Functions
    void Split(std::string &message, std::string* subs);
	//	
	//
    //
    bool receive_mode_;
	//Ports
	int network_socket_;
	//
    //Sockets server structure - 
	//required for creating the setup	
	struct sockaddr_in network_serv_;
	socklen_t network_len_;
};

#endif