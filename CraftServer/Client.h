#pragma once
//#include <iostream>
//#include "Talk.h"
//#pragma comment(lib,"ws2_32.lib")
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <WinSock2.h>
//#include <WS2tcpip.h>
//#include <stdarg.h>
#include <tuple>
//#include <sstream>
#include <queue>
#include <string>

typedef _W64 unsigned int UINT_PTR;
typedef UINT_PTR        SOCKET;

using namespace std;

class Client
{
public:
	Client();
	string createPacket(string type, ...);//message help message or talk message 't' then call send to send to client. puts it into correct format
	void send(string packet); // this send and process the information and packages it to the client.
	static SOCKET socket;
	uint16_t port;
	char *address;
	int id;
	string nick; //client nickname
	tuple<int, int, int, int, int> position;
	static void run();
private:
	static queue<string> queue; // queue of outgoing messages to the client


};