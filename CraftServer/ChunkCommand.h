#pragma once
#include "Command.h"
#include <string>

using namespace std;

class ChunkCommand:public Command
{
public:
	ChunkCommand(string chunkMessage ); //takes the message. its supposes to parse the message
	void execute()override;


private:
	int p, q, key;

};