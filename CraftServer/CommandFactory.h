#pragma once
#include "Command.h"
#include <string>
#include <memory>

class Client;

using namespace std;

class CommandFactory
{
public:
	CommandFactory(Client& );
//	~CommandFactory();
	static unique_ptr<Command> createCommand(Client& client1, string message); //creates command objects. Receive chunk message such as C which is a chunk
	static char search(string);//I

private:
	 Client& client;
	 
};
