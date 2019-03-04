#include <iostream>
#include "Algorithm_Interface.h"
#include <winsock2.h>

using namespace std;

int main()
{
	std::cout << "Starting Controller" << std::endl;

    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6111);

    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
    bool leave = false;
    while(!leave)
    {
        char recvBuffer[1024];
        recv(server, recvBuffer, sizeof(recvBuffer), 0);
        cout << "Buffer received is " << recvBuffer << std::endl;

        if(recvBuffer[0] == 'M')
        {
        	char buffer[1024]={'A', 'C', 'K', '_'};
            send(server, buffer, sizeof(buffer), 0);
            cout << "Message sent!" << endl;
            leave = true;
        }
    }
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;

	return 0;
}
