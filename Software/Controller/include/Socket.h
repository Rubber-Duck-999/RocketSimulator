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
#include "Logging.h"

#ifndef Socket_h
#define	Socket_h

class Socket
{
public:
	Socket() { };
	//
private:
	//
    //Functions
	void networkReceive();
	void networkSend();
	void networkSetup();
	void networkShutdown();
	//	
	//Pointers for messages to be set
	char* _messagePtr;
	//
	bool _run = false;
	//Ports for socket setup
	int _port = 8120;//PORT;
	//
	//Ports
	int _networkSock;
	//
    //Sockets server structure - 
	//required for creating the setup	
	struct sockaddr_in _networkServ;
	socklen_t _networkLen;
	//
	
};

#endif