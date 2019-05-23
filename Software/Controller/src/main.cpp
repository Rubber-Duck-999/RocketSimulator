#include "Logging.h"
#include "Socket.h"

int main()
{
	//cout << "Starting Controller" << endl;
    //Socket consoleSocket(6111);
    //consoleSocket.createSocket();
    //string consoleData;
    //consoleSocket.receiveFromConsole(consoleData);
    //cout << consoleData << endl;
    //consoleSocket.closeSocket();
    //
    init_log();
    BOOST_LOG_TRIVIAL(debug) << "Start up of node";
    Socket socket();
    // Algorithm algo;
    // ROCKET_SIMULATOR::rocketDataParameters rocketData;
    // ROCKET_SIMULATOR::launcherMissionParameters launcherData;
    // ROCKET_SIMULATOR::terrainMissionParameters terrainData;
    // ROCKET_SIMULATOR::stateDataParameters stateData;
    // ROCKET_SIMULATOR::algoData algoData;
    // startup("C:\\Users\\simon\\Documents\\Graphics.exe");
    // algo.get_rocketDataParameters(rocketData);
    // algo.get_terrainMissionParameters(terrainData);
    // while(!algo.getAlgoFinished())
    // {
    	// algo.set_algoData(algoData);
    // }
	// return 0;
}
 
