#include "socket.h"

void Socket::Split(std::string &message, std::string* subs)
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

void Socket::SaveMessage(std::string message)
{
    messages_.push_back(message);
}


void Socket::SendState(unsigned int statedata)
{
    namespace data = rocket_simulator;
    data::StateDataParameters sendingstate;
    BOOST_LOG_TRIVIAL(debug) << "Switching to;";
    switch(statedata)
    { 
        case 1:
            sendingstate.state = data::kCONFIGURED;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state;
            break;
        case 2:
            sendingstate.state = data::kREADY;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state;            
            break;
        case 3:
            sendingstate.state = data::kLAUNCH;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state;            
            break;
        case 4:
            sendingstate.state = data::kRETURN;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state;
            break;
        case 5:
            sendingstate.state = data::kSHUTDOWN;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state;
            break;
        default:
            sendingstate.state = data::kNON_CONFIGURED;
            BOOST_LOG_TRIVIAL(debug) << "State is back to: " << sendingstate.state;
    }
    current_state_ = sendingstate;
}


int Socket::SizeOfMessageList()
{
    BOOST_LOG_TRIVIAL(debug) << "The list of messages saved: " << messages_.size();
}


void Socket::NetworkReceive()
{
	char buffer[1024];
	buffer[1024] = '\0';
    BOOST_LOG_TRIVIAL(trace) << "Your receive mode is: " << receive_mode_;
    int received = recvfrom(network_socket_, buffer, 1024, 0, (struct sockaddr*)&network_serv_, (socklen_t *)&network_len_);
    std::string strbuffer = buffer;
    if (received > 0)
    {
        std::string subs[30];
        BOOST_LOG_TRIVIAL(error) << strbuffer;
        Split(strbuffer, subs);
        if (subs[0].find("M_") != std::string::npos) 
        {
            std::string expected = std::to_string(expected_id_);
            if (subs[0].find(expected) == std::string::npos)
            {
                BOOST_LOG_TRIVIAL(error) << "We may have missed a message";
            }
            BOOST_LOG_TRIVIAL(trace) << "A correct message has been received";
            SaveMessage(strbuffer);
            if (subs[1].find(state_configured_) != std::string::npos)
            {
                BOOST_LOG_TRIVIAL(info) << "Message: " << strbuffer;
                SendState(kConfigured);
                for(auto i = 3; i < 13; i++)
                {
                    subs[i].erase(std::remove(subs[i].begin(), subs[i].end(), ','), subs[i].end());
                    subs[i].erase(std::remove(subs[i].begin(), subs[i].end(), ']'), subs[i].end());
                    double number = std::atoi (subs[i].c_str());
                    algorithm_data_.push_back(number);
                    BOOST_LOG_TRIVIAL(trace) << "Configured Algo data size now: " << algorithm_data_.size();
                }
                receive_mode_ = false;
                expected_id_++;
            }
            else if (subs[1].find(state_ready_) != std::string::npos)
            {
                BOOST_LOG_TRIVIAL(info) << "Message: " << subs[1];
                SendState(kReady);
            }
            else if (subs[1].find(state_launch_) != std::string::npos)
            {
                BOOST_LOG_TRIVIAL(info) << "Message: " << subs[1];
                SendState(kLaunch);
            }
            else if (subs[1].find(state_return_) != std::string::npos)
            {
                BOOST_LOG_TRIVIAL(info) << "Message: " << subs[1];
                SendState(kReturn);
            }
            else if (subs[1].find(state_shutdown_) != std::string::npos)
            {
                BOOST_LOG_TRIVIAL(info) << "Message: " << subs[1];
                SendState(kShutdown);
            }                    
        }
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "We have no messages at all";
    }
}


void Socket::NetworkSend()
{
    BOOST_LOG_TRIVIAL(debug) << "We are sending a Ack Message";
	int send = 0;
	send = sendto(network_socket_, message_ptr_, (sizeof(message_ptr_) + 2), 0, (struct sockaddr*)&network_serv_, sizeof(struct sockaddr_in));
	if(send < 0)
	{
		BOOST_LOG_TRIVIAL(error) << "A severe error has occured on the simulator send";
	}
}

void Socket::Loop()
{
    while(receive_mode_)
    {
        NetworkReceive();
        rocket_simulator::StateDataParameters now = GetCurrentState();
        BOOST_LOG_TRIVIAL(info) << "Current state: " << now.state;
    }
}

void Socket::GetAlgorithmData(std::vector<double>& data)
{
    BOOST_LOG_TRIVIAL(debug) << "Passing algo data";
    BOOST_LOG_TRIVIAL(debug) << "Size: " << algorithm_data_.size();
    for(int i = 0; i < algorithm_data_.size(); i++)
    {
        BOOST_LOG_TRIVIAL(debug) << "Data value: " << algorithm_data_[i]; 
        data.push_back(algorithm_data_[i]);  
        algorithm_data_[i] = 0.0;
    }
}


void Socket::NetworkSetup()
{
	BOOST_LOG_TRIVIAL(debug) << "Creating Communications";
	BOOST_LOG_TRIVIAL(debug) << kPort;
	network_serv_.sin_family = AF_INET;
    network_serv_.sin_addr.s_addr = INADDR_ANY;
	network_serv_.sin_port = htons(kPort);
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

void Socket::NetworkShutdown()
{
	BOOST_LOG_TRIVIAL(debug) << "Closing Network";
	close(network_socket_);
}
