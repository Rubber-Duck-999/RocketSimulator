#ifndef DATASTRUCTURE_h
#define DATASTRUCTURE_h

namespace rocket_simulator
{	
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
		float  angle_of_launch_;
	};
	
	struct TerrainMissionParameters
	{
		double density_;
		double acceleration_due_to_gravity_;
	};
	
	struct LauncherMissionParameters
	{
		unsigned short int pilots_;
		unsigned short int time_to_launch_min;
		unsigned short int time_to_launch_sec;
	};
	
	struct StateDataParameters
	{
		enum CurrentState
		{
			kNON_CONFIGURED,
			kCONFIGURED,
			kREADY,
			kLAUNCH,
			kRETURN,
			kSHUTDOWN
		} state;
	};
    
	struct AlgoData
	{
		double position_axis_x;
		double position_axis_y;
		double position_axis_z;
		unsigned short int time_min = 0.0;
		unsigned short int time_sec = 0.0;
		unsigned short int time_milli_sec = 0.0;
	};
}

#endif
