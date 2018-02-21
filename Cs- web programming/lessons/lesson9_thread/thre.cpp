#include <iostream>
#include <chrono>
#include <thread>
class thread_guard
{
	std::thread &t;
public:
	thread_guard(std::thread & myt):t(myt) {}
	~thread_guard(){
		if(t.joinable())
		{
			t.join();
		}
	}
};

int f(int &n){
	for(int i = 0; i < n; i++)
	{
		std::cout << "." << std::endl;
	}
}
void func(){
	int n = 1000;
	std::cout << "N= " << &n << std::endl;
	std::thread t(f,std::ref(n));
	thread_guard g(t);
	try{
		//throw 5;
	}catch(int) {
		std::cerr << "All correct!" << std::endl; 
	}
}
int main(){
	func();		
	std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
	std::cout << "Main";
}
