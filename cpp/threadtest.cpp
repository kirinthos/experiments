#include <thread>
#include <iostream>
#include <chrono>


class A
{
private:
	std::thread _thread;

public:
	A() : _thread(&A::run, this) { }

	void run() { printf("ran.\n"); }

	void join() { if (_thread.joinable()) { _thread.join(); printf("joined thread\n"); } else printf("did not join thread\n"); }
};

int main(int arg, char** argv)
{
	A a;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	a.join();
	a.join();
	printf("quitting\n");

	return 0;
}
