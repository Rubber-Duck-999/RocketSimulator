#include "socket.h"

void Socket::Split(std::string &message, std::string* subs)
{
    BOOST_LOG_TRIVIAL(debug) << "Split function call";
}


std::string Socket::NetworkReceive()
{
    return "ID:101-State:1-Density:9.87-Gravity:1.22-Mass:80.0-DragX:0.3-DragY:0.3-Hori:1.0-Vert:1.0-Thrust:100.0-BurnTime:50.0-Flowrate:20.0-LaunchAngle:20.0";
}


void Socket::NetworkSend(std::string message)
{
    BOOST_LOG_TRIVIAL(debug) << "Function called - Send";
}


void Socket::NetworkSetup()
{
    BOOST_LOG_TRIVIAL(debug) << "Function called - Setup";
}

void Socket::NetworkShutdown()
{
   BOOST_LOG_TRIVIAL(debug) << "Function called - Shutdown";
}
