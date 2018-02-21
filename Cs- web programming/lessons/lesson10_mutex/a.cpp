#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <mutex>
#include <deque>

template <typename T>
class Stack
{
	std::deque<T> data;
	std::mutex mx;
public:
	void pop() {std::lock_guard<std::mutex> g(mx);
				data.pop_back();}
	T top() {std::lock_guard<std::mutex> g(mx);
				return data.back();}
	void push(T const &obj) {std::lock_guard<std::mutex> g(mx);
							data.push_back(obj);}
	size_t get_size() {std::lock_guard<std::mutex> g(mx);
						return data.size();}
};

void f()
{
	Stack<int> st;
	std::mutex mx;
	std::thread t1([&]{
						for(int i =0; i < 100; i++)
						{
							std::lock_guard<std::mutex> g(mx);
							st.push(i);
	std::chrono::milliseconds dura( 10 );
    std::this_thread::sleep_for( dura );
						}
					});
	std::thread t2([&]{
						for(int i =0; i < 100; i++)
						{
							std::lock_guard<std::mutex> g(mx);
							std::cout << st.top() << std::endl;
	std::chrono::milliseconds dura( 20 );
    std::this_thread::sleep_for( dura );
							st.pop();
						}
					});
	t1.join();
	t2.join();
}

int main(){	
	f();
	//std::chrono::milliseconds dura( 2000 );
    //std::this_thread::sleep_for( dura );
}
