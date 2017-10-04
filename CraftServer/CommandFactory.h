#pragma once
#include "Command.h"
#include <string>

using namespace std;

class CommandFactory
{
public:
	CommandFactory();
//	~CommandFactory();
	static Command& createCommand(string message);


private:

};
