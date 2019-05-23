#include "Socket.h"

void split(std::string &message, std::string* subs)
{
    std::istringstream iss(message);
    std::string sub;
	int i = 0;
    do
    {
        iss >> sub;
		subs[i] = sub;
		i++;
    } 
	while (iss);
}

void Socket::networkReceive()
{
	char buffer[1024];
	buffer[1024] = '\0';
	int received = recvfrom(_networkSock, buffer, 1024, 0, (struct sockaddr*)&_networkServ, (socklen_t *)&_networkLen);
	std::string strBuffer = buffer;
	if (received > 0)
	{
		BOOST_LOG_TRIVIAL(debug) << "A message has been received";
		std::string subs[9];
		split(strBuffer, subs);
		if (subs[1].find("M_") != std::string::npos) 
		{
			BOOST_LOG_TRIVIAL(debug) << "A correct ID message has been received";
		}
	}	
}

void Socket::networkSend()
{
    BOOST_LOG_TRIVIAL(debug) << "We are sending a Simulator Fire Message";
	int send = 0;
	send = sendto(_networkSock, _messagePtr, (sizeof(_messagePtr) + 2), 0, (struct sockaddr*)&_networkServ, sizeof(struct sockaddr_in));
	if(send < 0)
	{
		BOOST_LOG_TRIVIAL(error) << "A severe error has occured on the simulator send";
	}
}


void Socket::networkSetup()
{
	BOOST_LOG_TRIVIAL(debug) << "Creating Communications";
	BOOST_LOG_TRIVIAL(debug) << _port;
	_networkServ.sin_family = AF_INET;
    _networkServ.sin_addr.s_addr = INADDR_ANY;
	_networkServ.sin_port = htons(_port);
	_networkSock = socket(AF_INET, SOCK_DGRAM, 0);
	if (_networkSock < 0) 
	{
		BOOST_LOG_TRIVIAL(error) << "A severe error has occured on the simulator network receive socket";
	}
	if(bind(_networkSock,(struct sockaddr*)&_networkServ, sizeof(_networkServ)) == -1 )
 	{
 		std::cout << "Failed to Bind" << std::endl;
 	}
	_networkLen = sizeof(_networkServ);
}

void Socket::networkShutdown()
{
	BOOST_LOG_TRIVIAL(debug) << "Closing Simulator Network";
	close(_networkSock);
}
