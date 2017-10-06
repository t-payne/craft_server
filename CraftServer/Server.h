#pragma once
#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
//#include "config.h"
//#include "sqlite3.h"
//#include "noise.h"
//#include "world.h"
//#include <stdio.h>
//#include <vector>
//#include "Client.h"
//#include "Model.h"

using namespace std;
//struct WSADATA;
//typedef unsigned int UINT_PTR;
//typedef UINT_PTR        SOCKET;
//struct sockaddr_in;
//struct fd_set;
struct Model;
//typedef WSAData WSADATA;

class Server
{
public:
	Server(Model&);
	Server(int port, Model&);
	~Server();
	void initialize(int port);
	void run();
	//void parse();
	Model& model;

private:
	int port;
	SOCKET master, new_socket,  s;
	
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
