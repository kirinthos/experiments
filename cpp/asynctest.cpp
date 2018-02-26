//
// asynctest.cpp
//
// Created by Jeremiah Cunningham on 8/20/2015
//

#include <chrono>
#include <future>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

std::thread someFunction()
{
	std::thread t([]() {
		printf("starting rando\n");
		std::this_thread::sleep_for(std::chrono::seconds(2));
		printf("done with rando\n");
	});
	return std::move(t);
}

int main(int argc, char *argv[])
{
	std::vector< std::unique_ptr< std::thread > > threads;
	srand( time( NULL ) );
	for (int i = 0; i < 10; i++)
	{
		//std::async(std::launch::async, 
		std::unique_ptr< std::thread>  t(
		new std::thread(
		[i]() { 
			printf("%d start.\n", i);
			std::this_thread::sleep_for(std::chrono::microseconds(rand() % 1000));
			printf("%d done.\n", i); 
		}));

		threads.push_back(std::move(t));
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("main complete...joining\n");

	for (auto& t : threads)
		t->join();

	printf("now do it with async...\n");

	std::vector< std::future<void> > futures;
	for (int i = 0; i < 10; i++)
	{
		auto f = std::async(std::launch::async, 
		[i]() { 
			printf("%d start.\n", i);
			std::this_thread::sleep_for(std::chrono::microseconds(rand() % 1000));
			printf("%d done.\n", i); 
		});

	}

	printf("main complete...getting\n");

	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("done.\n");

	printf("\nrando test\n");
	auto t = someFunction();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	printf("joining\n");
	t.join();

	return 0;
}
