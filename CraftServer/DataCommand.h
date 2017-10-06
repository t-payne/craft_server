#pragma once
#include "Command.h"
#include <string>

using namespace std;

class DataCommand :public Command
{
public:
	DataCommand(string chunkMessage);//message comes in from client and gets packaged. string comes from client. Anything that gets called goes to the datacommand
	void execute()override;


private:
	int p, q, key;

};