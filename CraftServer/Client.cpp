#include "Client.h"
#include <iostream>
#include "Talk.h"
#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdarg.h>
#include <sstream>
#include <string>
using namespace std;


Client::Client()
{

}

void Client::send(string packet)
{
	queue.push(packet);
}

void Client::run()
{
	
	while (1)
	{
		string buf;
		if (queue.empty())
		{
			Sleep(5000);
			continue;
		}
		else
		{
			buf += queue.front();
			queue.pop();

		}
		::send(socket, buf.c_str(), buf.length(), 0);
	}
}
string Client::createPacket(string type, ...)
{
	ostringstream packetStream;
	string packet;
	va_list args;
	va_start(args, type);

	switch (type.at(0))
	{
	case 'A':

		break;
	case 'B':

		break;
	case 'C':
		//		ChunkCommand chunkObject;
		break;
	case 'D':

		break;
	case 'K':
		break;
	case 'L':

		break;
	case 'P':

		break;
	case 'R':

		break;
	case 'S':

		break;
	case 'T':
		break;
	case 'E':

		break;
	case 'V':

		break;
	case 'U':
		packetStream << "U,";
		for (int i = 0; i < 6; i++)
		{
			packetStream << va_arg(args, int)<<",";
		}
		
		packetStream<<'\n';

		break;
	}

	va_end(args);
	return packetStream.str();
}