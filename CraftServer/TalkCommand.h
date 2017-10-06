#pragma once
#include "Client.h"
#include <stdarg.h>
#include <string>
#include "Command.h"

using namespace std;
class TalkCommand:public Command
{
public:
	TalkCommand(string message); //sends back to client. use createpacket . parses
	void execute()override;

private:
	string message;
	//Client& client;
};