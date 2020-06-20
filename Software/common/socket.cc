#include "socket.h"


std::string Socket::NetworkReceive()
{
    char buffer[1024];
    buffer[1023] = '\0';
    BOOST_LOG_TRIVIAL(trace) << "Your receive mode is: " << receive_mode_;
    int received = recvfrom(network_socket_, buffer, 1024, 0, (struct sockaddr*)&network_serv_, (socklen_t *)&network_len_);
    if (received > 0)
    {
        BOOST_LOG_TRIVIAL(debug) << "Message received is: " << buffer;
        std::string strbuffer = buffer;
        return strbuffer;
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "We have no messages at all";
        std::string string_var;
        return string_var;
    }
}


void Socket::NetworkSend(std::string message)
{
    BOOST_LOG_TRIVIAL(debug) << "We are sending a Ack Message";
    int send = 0;
    int val = message.length();
    char message_send[message.length() + 1];
    strcpy(message_send, message.c_str());
    char* message_ptr_ = message_send;
    BOOST_LOG_TRIVIAL(debug) << "Sent: " << message_send;
    send = sendto(network_socket_, message_ptr_, (val), 0, (struct sockaddr*)&network_serv_, sizeof(struct sockaddr_in));
    if(send < 0)
    {
       BOOST_LOG_TRIVIAL(error) << "A severe error has occured on the simulator send";
    }
}


void Socket::NetworkSetup()
{
    BOOST_LOG_TRIVIAL(debug) << "Creating Communications";
    BOOST_LOG_TRIVIAL(debug) << rocket_simulator::kPort;
    network_serv_.sin_family = AF_INET;
    network_serv_.sin_addr.s_addr = INADDR_ANY;
    network_serv_.sin_port = htons(rocket_simulator::kPort);
    network_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (network_socket_ < 0) 
    {
       BOOST_LOG_TRIVIAL(error) << "A severe error has occured on the simulator network receive socket";
    }
    if(bind(network_socket_,(struct sockaddr*)&network_serv_, sizeof(network_serv_)) == -1 )
    {
       BOOST_LOG_TRIVIAL(error) << "Failed to Bind";
    }
    network_len_ = sizeof(network_serv_);
}
