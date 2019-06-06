#include "interface.h"

Interface::Interface()
{
    local_socket_.NetworkSetup();
    current_state_.state = rocket_simulator::kNON_CONFIGURED;    
    id_ = 101;
    world.density_ = 0.0;
    world.acceleration_due_to_gravity_ = 0.0;
    rocket.mass_ = 0.0;
    rocket.drag_axis_x_ = 0.0;
    rocket.drag_axis_y_ = 0.0;
    rocket.hori_cross_sect_area_ = 0.0;
    rocket.vert_cross_sect_area_ = 0.0;
    rocket.thrust_ = 0.0;
    rocket.burn_time_ = 0.0;
    rocket.flow_rate_ = 0.0;
    rocket.angle_of_launch_ = 0.0;
}

bool Interface::RunAlgo()
{
    algo.GetRocketDataParameters(rocket);
    algo.GetTerrainMissionParameters(world);
    algo.CreateRocketSimulation();
    return false;
}


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


void Interface::Receive()
{
    std::string message = local_socket_.NetworkReceive();
    if (message.length() > 1)
    {
        using namespace rocket_simulator;
        std::vector<std::string> vect;
        boost::split(vect, message, boost::is_any_of("-"));
        const unsigned int start = 0;
        for (unsigned int i = 0; i < vect.size(); i++) 
        {
            if(vect[i].find(kID) != std::string::npos) 
            {
                vect[i].erase(start,kID.length());
                unsigned int number = std::atof(vect[i].c_str());
                BOOST_LOG_TRIVIAL(error) << "ID: " << number;
            }
            else if(vect[i].find(kState) != std::string::npos) 
            {
                BOOST_LOG_TRIVIAL(error) << "Current State is: " << current_state_.state;
                vect[i].erase(start,kState.length());
                unsigned int val = std::atoi(vect[i].c_str());
                SendState(val);
                BOOST_LOG_TRIVIAL(error) << "State: " << vect[i];
                BOOST_LOG_TRIVIAL(error) << "Current State is: " << current_state_.state;
            }
            else if(vect[i].find(kDensity) != std::string::npos) 
            {
                vect[i].erase(start,kDensity.length());
                double number = std::atof(vect[i].c_str());
                world.density_ = number;
                BOOST_LOG_TRIVIAL(error) << "Density: " << number;
            }
            else if(vect[i].find(kGravity) != std::string::npos) 
            {
                vect[i].erase(start,kGravity.length());
                double number = std::atof(vect[i].c_str());
                world.acceleration_due_to_gravity_ = number;
                BOOST_LOG_TRIVIAL(error) << "Gravity: " << number;
            }
            else if(vect[i].find(kMass) != std::string::npos) 
            {
                vect[i].erase(start,kMass.length());
                double number = std::atof(vect[i].c_str());
                rocket.mass_ = number;
                BOOST_LOG_TRIVIAL(error) << "Mass: " << number;
            }  
            else if(vect[i].find(kDragXAxis) != std::string::npos) 
            {
                vect[i].erase(start,kDragXAxis.length());
                double number = std::atof(vect[i].c_str());
                rocket.drag_axis_x_ = number;
                BOOST_LOG_TRIVIAL(error) << "Drag X Axis: " << number;
            }    
            else if(vect[i].find(kDragYAxis) != std::string::npos) 
            {
                vect[i].erase(start,kDragYAxis.length());
                double number = std::atof(vect[i].c_str());
                rocket.drag_axis_y_ = number;
                BOOST_LOG_TRIVIAL(error) << "Drag Y Axis: " << number;
            }   
            else if(vect[i].find(kHori) != std::string::npos) 
            {
                vect[i].erase(start,kHori.length());
                double number = std::atof(vect[i].c_str());
                rocket.hori_cross_sect_area_ = number;
                BOOST_LOG_TRIVIAL(error) << "Horizontal: " << number;
            }       
            else if(vect[i].find(kVert) != std::string::npos) 
            {
                vect[i].erase(start,kVert.length());
                double number = std::atof(vect[i].c_str());
                rocket.vert_cross_sect_area_ = number;
                BOOST_LOG_TRIVIAL(error) << "Vertical: " << number;
            }   
            else if(vect[i].find(kThrust) != std::string::npos) 
            {
                vect[i].erase(start,kThrust.length());
                double number = std::atof(vect[i].c_str());
                rocket.thrust_ = number;
                BOOST_LOG_TRIVIAL(error) << "Thrust: " << number;
            }     
            else if(vect[i].find(kBurnTime) != std::string::npos) 
            {
                vect[i].erase(start,kBurnTime.length());
                double number = std::atof(vect[i].c_str());
                rocket.burn_time_ = number;
                BOOST_LOG_TRIVIAL(error) << "Burn Time: " << number;
            } 
            else if(vect[i].find(kFlowrate) != std::string::npos) 
            {
                vect[i].erase(start,kFlowrate.length());
                double number = std::atof(vect[i].c_str());
                rocket.flow_rate_ = number;
                BOOST_LOG_TRIVIAL(error) << "Flowrate: " << number;
            }
            else if(vect[i].find(kLaunchAngle) != std::string::npos) 
            {
                vect[i].erase(start,kLaunchAngle.length());
                double number = std::atof(vect[i].c_str());
                rocket.angle_of_launch_ = number;
                BOOST_LOG_TRIVIAL(error) << "Launch angle: " << number;
            }           
        }
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "We have no messages at all";
    }
    
    if(current_state_.state == rocket_simulator::kCONFIGURED)
    {
        RunAlgo();
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
