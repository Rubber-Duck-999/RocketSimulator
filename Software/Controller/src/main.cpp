/* #include <iostream>
#include <windows.h>
#include "Algorithm.h"
#include <winsock2.h>
#include "dataStructure.h"

using namespace std;

class Socket
{
public:
	Socket(int Port):_port(Port) {}
    void createSocket();
    void receiveFromConsole(string& receive);
    void sendToGraphics();
    void closeSocket();
private:
	int _port;
	bool leave = false;
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
};

void Socket::createSocket()
{
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
}


void Socket::receiveFromConsole(string& receive)
{
    while(!leave)
    {
        connect(server, (SOCKADDR *)&addr, sizeof(addr));
        cout << "Connected to server!" << endl;
        char recvBuffer[1024];
        recv(server, recvBuffer, sizeof(recvBuffer), 0);
        if(recvBuffer[0] == 'M')
        {
            cout << "We have received: " << recvBuffer << endl;
            cout << "Sending Acknowledgement" << endl;
        	char buffer[1024]={'A', 'C', 'K', '_', recvBuffer[0], '_', recvBuffer[3], recvBuffer[4], recvBuffer[5]};
            send(server, buffer, sizeof(buffer), 0);
            cout << "Message sent!" << endl;
            receive = recvBuffer;
            leave = true;
        }
    }
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
}


void Socket::sendToGraphics()
{
    while(!leave)
    {
        connect(server, (SOCKADDR *)&addr, sizeof(addr));
        cout << "Connected to server!" << endl;
        char recvBuffer[1024];
        recv(server, recvBuffer, sizeof(recvBuffer), 0);
        cout << "We have received: " << recvBuffer << endl;
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
}


void startup(LPCTSTR lpApplicationName)
{
   // additional information
   STARTUPINFO si;
   PROCESS_INFORMATION pi;

   // set the size of the structures
   ZeroMemory( &si, sizeof(si) );
   si.cb = sizeof(si);
   ZeroMemory( &pi, sizeof(pi) );

  // start the program up
  CreateProcess( lpApplicationName,   // the path
    "open",        // Command line
    NULL,           // Process handle not inheritable
    NULL,           // Thread handle not inheritable
    false,          // Set handle inheritance to FALSE
    0,              // No creation flags
    NULL,           // Use parent's environment block
    NULL,           // Use parent's starting directory
    &si,            // Pointer to STARTUPINFO structure
    &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
  );

  Sleep(5000);

  // Close process and thread handles.
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );
  std::cout << "Running main program" << std::endl;
}


int main()
{
	cout << "Starting Controller" << endl;
    //Socket consoleSocket(6111);
    //consoleSocket.createSocket();
    //string consoleData;
    //consoleSocket.receiveFromConsole(consoleData);
    //cout << consoleData << endl;
    //consoleSocket.closeSocket();
    //
    Algorithm algo;
    ROCKET_SIMULATOR::rocketDataParameters rocketData;
    ROCKET_SIMULATOR::launcherMissionParameters launcherData;
    ROCKET_SIMULATOR::terrainMissionParameters terrainData;
    ROCKET_SIMULATOR::stateDataParameters stateData;
    ROCKET_SIMULATOR::algoData algoData;
    startup("C:\\Users\\simon\\Documents\\Graphics.exe");
    algo.get_rocketDataParameters(rocketData);
    algo.get_terrainMissionParameters(terrainData);
    while(!algo.getAlgoFinished())
    {
    	algo.set_algoData(algoData);
    }
	return 0;
}
 */
 
int main()
{

   return 0;
}