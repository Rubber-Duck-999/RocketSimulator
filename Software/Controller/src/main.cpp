#include <iostream>
#include "Algorithm_Interface.h"
#include <winsock2.h>

using namespace std;

class Socket
{
	Socket(int Port):_port(Port) {}
    void createSocket();
    void sendData();
    void closeSocket();

	int _port;
	bool leave = false;
    std::string networkIPAddress = "127.0.0.1";
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
};

void Socket::createSocket()
{
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = networkIPAddress;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
}


void Socket::sendData()
{
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
    while(!leave)
    {
        char recvBuffer[1024];
        recv(server, recvBuffer, sizeof(recvBuffer), 0);

        if(recvBuffer[0] == 'M')
        {
        	char buffer[1024]={'A', 'C', 'K', '_'};
            send(server, buffer, sizeof(buffer), 0);
            cout << "Message sent!" << endl;
            leave = true;
        }
    }
}

void Socket::closeSocket()
{
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
}


int main()
{
	std::cout << "Starting Controller" << std::endl;

	return 0;
}
