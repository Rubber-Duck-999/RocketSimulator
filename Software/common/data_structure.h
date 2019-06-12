#include <string>

#ifndef DATA_STRUCTURE_h
#define DATA_STRUCTURE_h

namespace rocket_simulator
{	
    const int kConfigured = 1;
    const int kReady = 2;
    const int kLaunch = 3;
    const int kReturn = 4;
    const int kShutdown = 5;
    
    //Ports for socket setup
    const int kPort = 6111;
    
    const std::string kID = "ID:";
    const std::string kState = "State:";
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
    
    struct TerrainMissionParameters
    {
        double density_;
        double acceleration_due_to_gravity_;
        TerrainMissionParameters()
        {
            density_ = 1.22;
            acceleration_due_to_gravity_ = 9.8;
        };
    };
    
    struct LauncherMissionParameters
    {
        unsigned short int pilots_;
        unsigned short int time_to_launch_min;
        unsigned short int time_to_launch_sec;
    };
    
    typedef enum {kNON_CONFIGURED, kCONFIGURED, kREADY, kLAUNCH, kRETURN, kSHUTDOWN} STATE;
    
    typedef struct StateDataParameters
    {
        STATE state;
    }StateData;
    
    struct AlgoData
    {
        double position_axis_x_;
        double position_axis_y_;
        double velocity_x_;
        double velocity_y_;
        double time_milli_sec_;
        AlgoData(double position_axis_x, double position_axis_y,
                 double velocity_x, double velocity_y, 
                 double time_milli_sec): position_axis_x_(position_axis_x), 
                 position_axis_y_(position_axis_y), velocity_x_(velocity_x),
                 velocity_y_(velocity_y), time_milli_sec_(time_milli_sec) { };
                 
        AlgoData()
        {
            position_axis_x_ = 0.0;
            position_axis_y_ = 0.0;
            velocity_x_ = 0.0;
            velocity_y_ = 0.0;
            time_milli_sec_ = 0.0;            
        }
    };
    

    template<typename T, typename R>
    static inline auto Compare(T x, R y) -> decltype(x + y) const
    {
        return x < y ? y : x;
    }
}

#endif
