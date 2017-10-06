#pragma once
#include "Command.h"
#include <string>
#include <memory>


using namespace std;

class CommandFactory
{
public:
	CommandFactory();
//	~CommandFactory();
	static unique_ptr<Command> createCommand(string message); //creates command objects. Receive chunk message such as C which is a chunk


private:

};
