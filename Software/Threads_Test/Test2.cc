#include <boost/lockfree/spsc_queue.hpp>
#include <thread>
#include <iostream>

const int kMax = 10;
boost::lockfree::spsc_queue<int> q{kMax};
int sum = 0;

class producer
{
public:
    producer() {};
    ~producer() {};
    void RunAdder()
    {
        for (int i = 1; i <= kMax; ++i)
        {
            q.push(i);
            std::cout << "Produce: " << i << std::endl;
        }
    };
    
    void SumAdder()
    {
        int i;
        while (q.pop(i))
        {
            sum += i;
            std::cout << "Consume: " << i << std::endl;
        }
    };
};

int main()
{
    producer p1;
    producer p2;
    std::thread t1{&producer::RunAdder, &p1};
    std::thread t2{&producer::SumAdder, &p2};
    t1.join();
    t2.join();
    p2.SumAdder();
    std::cout << sum << '\n';
}