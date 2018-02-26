

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <Poco/Timespan.h>
#include <Poco/Thread.h>
#include <Poco/NObserver.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>
#include <Poco/Net/SocketConnector.h>
#include <Poco/Net/SocketNotification.h>

using Poco::AutoPtr;
using Poco::Timespan;
using Poco::NObserver;
using Poco::Thread;
using Poco::Net::SocketAddress;
using Poco::Net::SocketAcceptor;
using Poco::Net::SocketConnector;
using Poco::Net::SocketReactor;
using Poco::Net::StreamSocket;
using Poco::Net::SocketNotification;
using Poco::Net::ReadableNotification;
using Poco::Net::WritableNotification;



void connectThread()
{

	printf("connect thread.\n");
}

void serverThread()
{

	printf("server thread.\n");
}

int main(int argc, char *argv[])
{
	printf("\n\nUDP Socket Test\n------------------------\n\n");

	std::thread t1(&connectThread),
				t2(&serverThread);


	t1.join();
	t2.join();
	printf("\n\nmain complete.\n\n");

	return 0;
}
