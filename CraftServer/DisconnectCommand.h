#pragma once
#include "Command.h"
#include <string>

using namespace std;

class DisconnectCommand :public Command
{
public:
	DisconnectCommand(string chunkMessage);
	void execute() override;


private:
	int p, q, key;

};
