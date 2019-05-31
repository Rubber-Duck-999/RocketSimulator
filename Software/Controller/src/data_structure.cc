#include "data_structure.h"

namespace rocket_simulator 
{
    void states::Add(StateDataParameters& sendingstate)
    {
        for (int i = 1; i <= kMaxStateQueue; ++i)
        {
            //StateDataParameters sendingstate;
            sendingstate.state = kCONFIGURED;
            statequeue.push(sendingstate);
            std::cout << "Produce: " << i << std::endl;
        }
    };

    void states::Remove(StateDataParameters& i)
    {
        //StateDataParameters i;
        while (statequeue.pop(i))
        {
            std::cout << "Consume: " << i.state << std::endl;
        }
    };
}