

#include "Interface_set.h"
#include <iostream>
#include <string>
#include <sstream> // for std::stringstream
#include <cstdlib> // for exit()
#include "dataStructure.h"


void sendData()
{
	Interface* ptrRocket = new Interface;
	//std::cout << ptrRocket << std::endl;
	//ROCKET_SIMULATOR::rocketDataParameters* RocketData;
	//ROCKET_SIMULATOR::terrainMissionParameters* TerrainData;
	//ROCKET_SIMULATOR::stateDataParameters* StateData;
	//ptrRocket->receive_rocketDataParameters(RocketData);
	//rocketAlgoInterface.receive_terrainMissionParameters(*terrainData);
	//rocketAlgoInterface.receive_stateDataParameters(*stateData);
}

int main(int argc, char** argv)
{
	std::cout << "Starting Node" << std::endl;
	if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		exit(1);
	}

	std::stringstream convert(argv[1]); // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myint;
	if (!(convert >> myint)) // do the conversion
		myint = 0; // if conversion fails, set myint to a default value

	std::cout << "Got integer: " << myint << '\n';
	sendData();
    return 0;
}



