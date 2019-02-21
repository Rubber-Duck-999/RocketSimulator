#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

namespace ROCKET_SIMULATOR
{	
	struct rocketDataParameters
	{
		double mass;
		double dragAxisX;
		double dragAxisY;
		double horiCrossSectArea;
		double vertCrossSectArea;
		double thrust;
		double burnTime;
		double flowRate;
		float  angleOfLaunch;
	};
	
	struct terrainMissionParameters
	{
		double density;
		double accelerationDueToGravity;
	};
	
	struct launcherMissionParameters
	{
		unsigned short int pilots;
		unsigned short int timeToLaunchMin;
		unsigned short int timeToLaunchSec;
	};
	
	struct stateDataParameters
	{
		enum currentState
		{
			NON_CONFIGURED,
			CONFIGURED,
			READY,
			LAUNCH,
			RETURN,
			SHUTDOWN
		} state;
	};
	struct algoData
	{
		double positionAxisX;
		double positionAxisY;
		double positionAxisZ;
		unsigned short int timeMin = 0.0;
		unsigned short int timeSec = 0.0;
		unsigned short int timeMilliSec = 0.0;
	};

}

#endif
