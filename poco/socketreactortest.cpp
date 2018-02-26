//
// socketreactortest.cpp
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
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>
#include <Poco/Net/SocketConnector.h>
#include <Poco/Net/SocketNotification.h>

#define USE_CUSTOM 1


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

class Connection
{
public:
	Connection() { }
	virtual ~Connection() { }

	void hasConnected() { printf("whoo! we connected...\n"); }
};

class ServiceHandler
{
public:
	ServiceHandler(StreamSocket socket, SocketReactor& reactor) : _socket(socket), _reactor(reactor) { }
	virtual ~ServiceHandler() { printf("~ServiceHandler\n"); }

	void onWritable(const AutoPtr<WritableNotification>& notification)
	{
		std::string request = "Hello, World!";
		_socket.sendBytes(request.c_str(), request.length());
	}

	void onReadable(const AutoPtr<ReadableNotification>& notfiication)
	{
		char buf[100];
		int bytes = _socket.receiveBytes(buf, 99);
		if (bytes > 0)
		{
			buf[99] = '\0';
			printf("received: %s\n", buf);
		}
		else
		{
			_reactor.removeEventHandler(_socket, NObserver<ServiceHandler, ReadableNotification>(*this, &ServiceHandler::onReadable));
			_reactor.removeEventHandler(_socket, NObserver<ServiceHandler, WritableNotification>(*this, &ServiceHandler::onWritable));
		}
	}

private:
	StreamSocket _socket;
	SocketReactor& _reactor;
};

class ServiceInitializer
{
public:
	ServiceInitializer (const StreamSocket& socket , SocketReactor& reactor)
		: _socket(socket), _reactor(reactor)
	{
		printf("Connector ServiceInitializer created...\n");
#ifndef USE_CUSTOM
		ServiceHandler* handler = new ServiceHandler(socket, reactor);
		reactor.addEventHandler(socket, NObserver<ServiceHandler, ReadableNotification>(*handler, &ServiceHandler::onReadable));
		reactor.addEventHandler(socket, NObserver<ServiceHandler, WritableNotification>(*handler, &ServiceHandler::onWritable));
#endif
	}
	virtual ~ServiceInitializer () { }

	void setConnection(Connection* conn) { _connection = conn; }
	Connection* getConnection() { return _connection; }

private:
	const StreamSocket& _socket;
	SocketReactor& _reactor;
	Connection* _connection;
};

class CustomSocketConnector : public SocketConnector<ServiceInitializer>
{
public:
	CustomSocketConnector(SocketAddress& address, Connection* conn) : SocketConnector(address), _connection(conn) { }
	CustomSocketConnector(SocketAddress& address, SocketReactor& reactor, Connection* conn) : SocketConnector(address, reactor), _connection(conn) { }
	virtual ~CustomSocketConnector() { }

protected: 

	ServiceInitializer* createServiceHandler() override
	{
		_connection->hasConnected();
		return nullptr;
	}

private:
	Connection* _connection;
};


int main(int argc, char *argv[])
{
	Connection* conn = new Connection();
	SocketAddress address("localhost:12000");
	SocketReactor reactor(Timespan(0, 0, 0, 1, 0));
#ifndef USE_CUSTOM
	SocketConnect<ServiceInitializer> connector(address, reactor);
#else
	CustomSocketConnector connector(address, reactor, conn);
#endif

	Thread thread;
	thread.start(reactor);
	thread.join();

	delete conn;

	printf("connect main complete.\n");
	return 0;
}
