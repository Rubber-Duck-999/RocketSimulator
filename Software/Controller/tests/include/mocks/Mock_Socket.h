#ifndef MOCK_SOCKET_h
#define MOCK_SOCKET_h

#include "socket.h"
#include "gmock/gmock.h"
#include <string>

class MockSocket : public Socket
{
public:
    MockSocket(){}
    ~MockSokcet(){}
    MOCK_METHOD0(NetworkReceive, std::string());
};

#endif