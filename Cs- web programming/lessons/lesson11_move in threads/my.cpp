#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <deque>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>

int sum(int a, int b)
{
	return a + b;
}

int main(){	
	std::vector<int> v{1,2,3,4,5,6};
	std::vector<int> v2;
	for(auto i : v) std::cout << i << std::endl;
	auto p = std::bind(sum,5,std::placeholders::_1);
	std::transform(v.begin(),v.end(),std::back_inserter(v2),p);
	std::cout << std::endl;
	for(auto i : v2) std::cout << i << std::endl;
	//std::chrono::milliseconds dura( 2000 );
    //std::this_thread::sleep_for( dura );
}
