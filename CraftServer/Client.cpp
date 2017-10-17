#include "Client.h"
#include <iostream>
#include "TalkCommand.h"
#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdarg.h>
#include <sstream>
#include <string>
#include "Server.h"
#include "Model.h"
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
	case NULL:
		send("Type 't' to chat. Type '/' to type commands:");
		break;
	//case 

	}
	//switch (type.at(0))
	//{
	//case 'A':

	//	break;
	//case 'B':

	//	break;
	//case 'C':
	//	//		ChunkCommand chunkObject;
	//	break;
	//case 'D':

	//	break;
	//case 'K':
	//	break;
	//case 'L':

	//	break;
	//case 'P':

	//	break;
	//case 'R':

	//	break;
	//case 'S':

	//	break;
	//case 'T':
	//	break;
	//case 'E':

	//	break;
	//case 'V':

	//	break;
	//case 'U':
	//	packetStream << "U,";
	//	for (int i = 0; i < 6; i++)
	//	{
	//		packetStream << va_arg(args, int)<<",";
	//	}
	//	
	//	packetStream<<'\n';

	//	break;
	//}

	va_end(args);
	return packetStream.str();
}
//Client& Client::remove()
//{
//	
//	//int max = server.getMaxClient();
//	//for (int i = 0; i <max ; i++)
//	//{
//	//	if (model.getClient(i).socket == 0)
//	//	{
//	//		Client& client = model.getClient(i);
//	//		client.socket = new_socket;
//	//		client.port = ntohs(address.sin_port);
//	//		client.address = inet_ntoa(address.sin_addr);
//	//		client.id = i;
//	//		ConnectCommand ccmd(model, client);
//	//		//unique_ptr<Command> cmd_ptr = );
//	//		model.addCommand(make_unique<Command>(ccmd));
//	//		printf("Adding to list of sockets at index %d \n", i);
//	//		break;
//	//	}
//	//}
//	return *this;
//}