#include <string>

#ifndef DATA_STRUCTURE_h
#define DATA_STRUCTURE_h

namespace rocket_simulator
{
    /////////////////////////////////////////////
    // Constants
    /////////////////////////////////////////////    
    const int kPort = 6111;
    
    const std::string kID = "ID:";
    const std::string kDensity = "Density:";
    const std::string kGravity = "Gravity:";
    const std::string kMass = "Mass:";
    const std::string kDragXAxis = "DragX:";
    const std::string kDragYAxis = "DragY:";
    const std::string kHori = "Hori:";
    const std::string kVert = "Vert:";
    const std::string kThrust = "Thrust:";
    const std::string kBurnTime = "BurnTime:";
    const std::string kFlowrate = "Flowrate:";
    const std::string kLaunchAngle = "LaunchAngle:";
    const std::string kPilots = "Pilot:";
    const std::string kSec = "Sec:";
    const std::string kStartup = "//mnt//c//Users//simon//Documents//Simulation";
    const std::string kConfig = "//mnt//c//Users//simon//Documents//Projects/C++//RocketSimulator//Software//Controller//config//use.conf";
    const std::string kWindowName = "2D Rocket Simulator";
    const int kWindowSizeHori = 640;
    const int kWindowSizeVert = 480;
    const unsigned int kMinXAxisLength = 0; // 0 m
    const unsigned int kMaxXAxisLength = 10000; // 10,000 m
    const double kMinHeight = -50.0; // -50m
    const double kMaxHeight = 255.0; // 255m
    const double kPI = 3.1415926;
    const unsigned int kLaunchLength = 1000;
    /////////////////////////////////////////////


    /////////////////////////////////////////////
    // Rocket Data
    /////////////////////////////////////////////
    struct RocketDataParameters
    {
        double mass_;
        double drag_axis_x_;
        double drag_axis_y_;
        double hori_cross_sect_area_;
        double vert_cross_sect_area_;
        double thrust_;
        double burn_time_;
        double flow_rate_;
        double angle_of_launch_;
        
        RocketDataParameters()
        {
            mass_ = 0.0;
            drag_axis_x_ = 0.0;
            drag_axis_y_ = 0.0;
            hori_cross_sect_area_ = 0.0;
            vert_cross_sect_area_ = 0.0;
            thrust_ = 0.0;
            burn_time_ = 0.0;
            flow_rate_ = 0.0;
            angle_of_launch_ = 0.0;
        };
    };    
    /////////////////////////////////////////////
    
    
    /////////////////////////////////////////////
    // Terrain Data
    /////////////////////////////////////////////
    struct TerrainMissionParameters
    {
        double density_;
        double acceleration_due_to_gravity_;
        TerrainMissionParameters()
        {
            density_ = 1.22;
            acceleration_due_to_gravity_ = 9.81;
        };
    };
    /////////////////////////////////////////////
    
    
    /////////////////////////////////////////////
    // Launcher Data
    /////////////////////////////////////////////
    typedef enum {kBOB, kFRED, kRYAN, kSARAH, kGRACE} PILOTS;
    
    struct LauncherMissionParameters
    {
        PILOTS pilots_;
        unsigned short int time_to_launch_sec_;
    };
    /////////////////////////////////////////////
    
    
    /////////////////////////////////////////////
    // State Data
    /////////////////////////////////////////////
    typedef enum {kNON_CONFIGURED, kCONFIGURED, kREADY, kLAUNCH, kRETURN, kSHUTDOWN} STATE;
    
    typedef struct StateDataParameters
    {
        STATE state_;
    }StateData;
    /////////////////////////////////////////////
    
    
    /////////////////////////////////////////////
    // Algo Data
    /////////////////////////////////////////////
    struct AlgoData
    {
        double position_axis_x_;
        double position_axis_y_;
        double angle_of_direction_;
        double time_milli_sec_;
        AlgoData(double position_axis_x, double position_axis_y,
                 double angle_of_direction, double time_milli_sec): position_axis_x_(position_axis_x), 
                 position_axis_y_(position_axis_y), angle_of_direction_(angle_of_direction), 
                 time_milli_sec_(time_milli_sec) { };
                 
        AlgoData()
        {
            position_axis_x_ = 0.0;
            position_axis_y_ = 0.0;
            angle_of_direction_ = 0.0;
            time_milli_sec_ = 0.0;            
        }
    };
    /////////////////////////////////////////////
}

#endif
