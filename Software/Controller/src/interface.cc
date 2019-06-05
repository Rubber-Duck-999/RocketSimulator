#include "interface.h"

void Interface::SaveMessage(std::string message)
{
    //messages_.push_back(message);
}


void Interface::SendState(unsigned int statedata)
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


/*
int Interface::SizeOfMessageList()
{
    BOOST_LOG_TRIVIAL(debug) << "The list of messages saved: " << messages_.size();
}*/


void Interface::Receive()
{
    std::string message = local_socket_.NetworkReceive();
    if (message.length() > 1)
    {
        std::vector<std::string> vect;
        boost::split(vect, message, boost::is_any_of("-"));
        for (int i = 0; i < vect.size(); i++) 
        {
            std::string ID = "ID:";
            if(vect[i].find(ID) != std::string::npos) 
            {
                vect[i].erase(0,ID.length());
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "ID: " << number;
            }
            else if(vect[i].find("State:") != std::string::npos) 
            {
                BOOST_LOG_TRIVIAL(error) << "Current State is: " << current_state_.state;
                vect[i].erase(0,6);
                unsigned int val = std::atoi(vect[i].c_str());
                SendState(val);
                BOOST_LOG_TRIVIAL(error) << "State: " << vect[i];
                BOOST_LOG_TRIVIAL(error) << "Current State is: " << current_state_.state;
            }
            else if(vect[i].find("Density:") != std::string::npos) 
            {
                vect[i].erase(0,8);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Density: " << number;
            }
            else if(vect[i].find("Gravity:") != std::string::npos) 
            {
                vect[i].erase(0,8);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Gravity: " << number;
            }
            else if(vect[i].find("Mass:") != std::string::npos) 
            {
                vect[i].erase(0,5);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Mass: " << number;
            }  
            else if(vect[i].find("DragX:") != std::string::npos) 
            {
                vect[i].erase(0,6);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Drag X Axis: " << number;
            }    
            else if(vect[i].find("DragY:") != std::string::npos) 
            {
                vect[i].erase(0,6);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Drag Y Axis: " << number;
            }   
            else if(vect[i].find("Hori:") != std::string::npos) 
            {
                vect[i].erase(0,5);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Horizontal: " << number;
            }       
            else if(vect[i].find("Vert:") != std::string::npos) 
            {
                vect[i].erase(0,5);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Vertical: " << number;
            }   
            else if(vect[i].find("Thrust:") != std::string::npos) 
            {
                vect[i].erase(0,7);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Thrust: " << number;
            }     
            else if(vect[i].find("BurnTime:") != std::string::npos) 
            {
                vect[i].erase(0,9);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Burn Time: " << number;
            } 
            else if(vect[i].find("Flowrate:") != std::string::npos) 
            {
                vect[i].erase(0,9);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Flowrate: " << number;
            }
            else if(vect[i].find("LaunchAngle:") != std::string::npos) 
            {
                vect[i].erase(0,12);
                double number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "Launch angle: " << number;
            }           
        }
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "We have no messages at all";
    }
}


void Interface::GetAlgorithmData(std::vector<double>& data)
{
    /*
    BOOST_LOG_TRIVIAL(debug) << "Passing algo data";
    BOOST_LOG_TRIVIAL(debug) << "Size: " << algorithm_data_.size();
    for(int i = 0; i < algorithm_data_.size(); i++)
    {
        BOOST_LOG_TRIVIAL(debug) << "Data value: " << algorithm_data_[i]; 
        data.push_back(algorithm_data_[i]);  
        algorithm_data_[i] = 0.0;
    }
    */
}
