#include "logging.h"
#include "socket.h"
#include "config_reader.h"

int main()
{
    init_log();
    BOOST_LOG_TRIVIAL(debug) << "Start up of node";
    //
    Socket localsocket;
    localsocket.NetworkSetup();
    localsocket.NetworkReceive();
    //localsocket.NetworkSend();
    localsocket.NetworkShutdown();
    //
    ConfigurationReader config;
    config.SetConfigValues();
    return 0;
}
 
