#include <boost/lockfree/spsc_queue.hpp>
#include <thread>
#include <iostream>

const int kMax = 10;
boost::lockfree::spsc_queue<int> q{kMax};
int sum = 0;

void produce()
{
   for (int i = 1; i <= kMax; ++i)
   {
      q.push(i);
      std::cout << "Produce: " << i << std::endl;
   }
}

void consume()
{
   int i;
   while (q.pop(i))
   {
      sum += i;
      std::cout << "Consume: " << i << std::endl;
   }
}

int main()
{
   std::thread t1{produce};
   std::thread t2{consume};
   t1.join();
   t2.join();
   consume();
   std::cout << sum << '\n';
}