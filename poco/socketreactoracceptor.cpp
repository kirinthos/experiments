//
// socketreactoracceptor.cpp
//
// Created by Jeremiah Cunningham on 8/24/2015
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <Poco/Timespan.h>
#include <Poco/Thread.h>
#include <Poco/NObserver.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/ServerSocket.h>
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
using Poco::Net::ServerSocket;
using Poco::Net::SocketNotification;
using Poco::Net::ReadableNotification;
using Poco::Net::WritableNotification;


class ServiceHandler
{
public:
	ServiceHandler(StreamSocket socket, SocketReactor& reactor) : _socket(socket), _reactor(reactor) { }
	virtual ~ServiceHandler() { printf("~ServiceHandler\n"); }

	void onReadable(const AutoPtr<ReadableNotification>& notification)
	{
		char buf[100];
		int bytes = _socket.receiveBytes(buf, 99);
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			printf("received: %s\n", buf);
			_request = buf;
		}
		else
		{
			_reactor.removeEventHandler(_socket, NObserver<ServiceHandler, ReadableNotification>(*this, &ServiceHandler::onReadable));
			_reactor.removeEventHandler(_socket, NObserver<ServiceHandler, WritableNotification>(*this, &ServiceHandler::onWritable));
			_socket.close();
			delete this;
		}
	}

	void onWritable(const AutoPtr<WritableNotification>& notification)
	{
		if (!_request.empty())
		{
			_socket.sendBytes(_request.c_str(), _request.length());
			_request.clear();
		}
	}

private:
	StreamSocket _socket;
	SocketReactor& _reactor;
	std::string _request;
};


class ServiceInitializer
{
public:
	ServiceInitializer(StreamSocket& socket, SocketReactor& reactor)
		: _socket(socket), _reactor(reactor)
	{
		printf("Acceptor ServiceInitializer created...\n");
		ServiceHandler* handler = new ServiceHandler(_socket, _reactor);
		reactor.addEventHandler(_socket, NObserver<ServiceHandler, ReadableNotification>(*handler, &ServiceHandler::onReadable));
		reactor.addEventHandler(_socket, NObserver<ServiceHandler, WritableNotification>(*handler, &ServiceHandler::onWritable));
	}

	virtual ~ServiceInitializer()
	{
		printf("~ServiceInitializer\n");
	}

private:
	StreamSocket& _socket;
	SocketReactor& _reactor;

};

int main(int argc, char *argv[])
{
	ServerSocket socket(12000);
	SocketReactor reactor(Timespan(0, 0, 0, 1, 0));
	SocketAcceptor<ServiceInitializer> acceptor(socket, reactor);

	Thread thread;
	thread.start(reactor);
	thread.join();

	printf("Acceptor main complete.\n");
	return 0;
}
