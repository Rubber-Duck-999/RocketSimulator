#include "interface.h"

Interface::Interface()
{
    local_socket_.NetworkSetup();
    current_state_.state_ = rocket_simulator::kNON_CONFIGURED;    
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
    pilot_set_ = false;
}


void Interface::Loop()
{
    local_socket_.SetReceive(true);
    while(current_state_.state_ != rocket_simulator::kSHUTDOWN)
    {
        Receive(local_socket_.NetworkReceive());
        if(current_state_.state_ == rocket_simulator::kCONFIGURED)
        {
            if(RunAlgo())
            {
                current_state_.state_ = rocket_simulator::kREADY;
                std::string message = std::to_string(id_);
                local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "2");
            }
            else
            {
                current_state_.state_ = rocket_simulator::kNON_CONFIGURED;
                std::string message = std::to_string(id_);
                local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "0");
            }
        }
        else if(current_state_.state_ == rocket_simulator::kLAUNCH)
        {
            RunSimulation();
            SendState(5);
            std::string message = std::to_string(id_);
            local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "5");
        }
    }
}


bool Interface::RunSimulation()
{
    BOOST_LOG_TRIVIAL(debug) << "Starting run of Graphical Simulation";
    //RunProcess(rocket_simulator::kStartup);
}


bool Interface::RunAlgo()
{
    BOOST_LOG_TRIVIAL(debug) << "Starting call of Algo";
    algo.GetRocketDataParameters(rocket);
    algo.GetTerrainMissionParameters(world);
    if(algo.CreateRocketSimulation())
    {
        GetAlgorithmData(algo_data_);
        return true;
    }
    else
    {
        return false;
    }
}


bool Interface::SetCorrect(int number)
{
    if(id_ == number)
    {
        id_++;
        BOOST_LOG_TRIVIAL(trace) << "Id matches message id, "
                                 << "updating number";
        return true;
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "Id doesn't match, dismissing message";
        return false;
    }
}        
        
        
void Interface::SendState(unsigned int statedata)
{
    namespace data = rocket_simulator;
    data::StateDataParameters sendingstate;
    std::string message = std::to_string(id_);
    BOOST_LOG_TRIVIAL(debug) << "Switching to:";
    switch(statedata)
    { 
        case 1:
            sendingstate.state_ = data::kCONFIGURED;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state_;
            break;
        case 2:
            sendingstate.state_ = data::kREADY;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state_;
            break;
        case 3:
            sendingstate.state_ = data::kLAUNCH;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state_;
            local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "3");
            break;
        case 4:
            sendingstate.state_ = data::kRETURN;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state_;
            if(current_state_.state_ == data::kREADY)
            {
                local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "2");
            }
            else
            {
                local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "1");
            }
            break;
        case 5:
            sendingstate.state_ = data::kSHUTDOWN;
            BOOST_LOG_TRIVIAL(debug) << "State change is: " << sendingstate.state_;
            local_socket_.NetworkSend("ID:" + message + "-" + "State:" + "5"); 
            break;
        default:
            sendingstate.state_ = data::kNON_CONFIGURED;
            BOOST_LOG_TRIVIAL(debug) << "State is back to: " << sendingstate.state_;
    }
    current_state_ = sendingstate;
}


void Interface::SetPilots(unsigned int pilot)
{
    namespace data = rocket_simulator;
    data::LauncherMissionParameters current_pilot;
    BOOST_LOG_TRIVIAL(debug) << "Switching to this pilot:";
    switch(pilot)
    { 
        case 0:
            current_pilot.pilots_ = data::kBOB;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
            break;
        case 1:
            current_pilot.pilots_ = data::kFRED;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
            break;
        case 2:
            current_pilot.pilots_ = data::kRYAN;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
            break;
        case 3:
            current_pilot.pilots_ = data::kSARAH;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
            break;
        case 4:
            current_pilot.pilots_ = data::kGRACE;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
            break;
        default:
            current_pilot.pilots_ = data::kBOB;
            BOOST_LOG_TRIVIAL(debug) << "Pilot is: " << current_pilot.pilots_;
    }
    launcher.pilots_ = current_pilot.pilots_;
}


void Interface::Receive(std::string message)
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
            SetCorrect(number);
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
            SendState(1);
        }
        else if(vect[i].find(kPilots) != std::string::npos)
        {
            vect[i].erase(start,kPilots.length());
            unsigned int number = std::atoi(vect[i].c_str());
            SetPilots(number);
            BOOST_LOG_TRIVIAL(error) << "Pilot: " << number;
        }
        else if(vect[i].find(kSec) != std::string::npos)
        {
            vect[i].erase(start,kSec.length());
            unsigned int number = std::atoi(vect[i].c_str());
            launcher.time_to_launch_sec_ = number;
            BOOST_LOG_TRIVIAL(error) << "Time to Launch Seconds: " << number;
            SendState(3);
        }
    }
}


void Interface::GetAlgorithmData(std::vector<rocket_simulator::AlgoData>& data)
{
    BOOST_LOG_TRIVIAL(debug) << "Passing algo data";
    BOOST_LOG_TRIVIAL(debug) << "Size: " << algo.algo_data_.size();
    data = algo.algo_data_;
}
