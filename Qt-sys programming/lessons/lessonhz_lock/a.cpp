#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <deque>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>

class Array{
	int  arr[1000];
	mutable std::mutex m;
public:
	void set(int index, int value)
	{
		std::lock_guard<std::mutex> g(m);
		arr[index] = value;
	}
	int operator[] (int index)const
	{
		std::lock_guard<std::mutex> g(m);
		return arr[index];
	}
	bool operator==(Array const & obj)
	{
std::lock(obj.m,m);
std::lock_guard<std::mutex> g1(m,std::adopt_lock);
			std::chrono::milliseconds dura( 10 );
			std::this_thread::sleep_for( dura );
std::lock_guard<std::mutex> g2(obj.m,std::adopt_lock);
		for(int i = 0; i< 1000; i++)
		{
			std::cerr << i << std::endl;
			if(arr[i] != obj.arr[i]) return false;
		}
		return true;
	}
};
void f()
{
	Array ob1, ob2;
	for(int i = 0; i < 1000; i++)
	{
		ob1.set(i,i);
		ob2.set(i,i);
	}
	std::thread t1([&]
					{
						if(ob1 == ob2)
						std::cout << "True T1";
						else std::cout << "False T1";
					});
	std::thread t2([&]
					{
						if(ob2 == ob1)
						std::cout << "True T2";
						else std::cout << "False T2";
					});
	t1.join();
	t2.join();
}

int main(){	
	f();
		
}
