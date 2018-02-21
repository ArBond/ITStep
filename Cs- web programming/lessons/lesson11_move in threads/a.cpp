#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <deque>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>

class thread_guard {
public:
	std::thread t;
	explicit thread_guard(std::thread myt): t(std::move(myt))
	{
		if(!t.joinable()) throw std::logic_error("MyError");
	}
	~thread_guard() {t.join();}
	thread_guard(thread_guard&& obj) 
	{
		t = std::move(obj.t);
		
	}
	thread_guard(thread_guard const &) = delete;
	thread_guard& operator=(thread_guard const &) = delete;
};

std::mutex mx;
void hey() {
	std::lock_guard<std::mutex> g(mx);
	std::cout << "Hey" << std::endl;
}

void f()
{
	std::vector<thread_guard> v;
	for(int i = 0; i < 20; i++) 
	v.push_back(thread_guard{std::thread(hey)});
	//-------
	
}


int main(){	
	f();
	//std::chrono::milliseconds dura( 2000 );
    //std::this_thread::sleep_for( dura );
}
