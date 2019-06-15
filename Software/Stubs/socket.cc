#include "socket.h"

void Socket::Split(std::string &message, std::string* subs)
{
    BOOST_LOG_TRIVIAL(debug) << "Split function call";
}


std::string Socket::NetworkReceive()
{
    return "";
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
