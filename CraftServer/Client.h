#pragma once
#include <iostream>
#include "Talk.h"
#include <WinSock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WS2tcpip.h>
#include <stdarg.h>

using namespace std;

class Client

{
public:
	Client();
	void send(va_list args,string response);
	SOCKET socket;
	uint16_t port;
	char *address;

private:

	int id;
	int position;


};