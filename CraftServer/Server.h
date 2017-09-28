#pragma once
#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "config.h"
#include "sqlite3.h"
#include "noise.h"
#include "world.h"
#include <stdio.h>



using namespace std;

class Server
{
public:
	Server();
	Server(int port);
	~Server();
	void initialize(int port);
	void run();
	void parse();

private:
	int port;
	SOCKET master, new_socket, client_socket[30], s;
	int max_clients = 30, activity, addrlen, i, valread;
	WSADATA wsa;
	struct sockaddr_in server, address;
	char *message = "ECHO Daemon v1.0 \r\n";
	//size of our receive buffer, this is string length.
	int MAXRECV = 1024;
	//set of socket descriptors
	fd_set readfds;
	//1 extra for null character, string termination
	char *buffer;


};
