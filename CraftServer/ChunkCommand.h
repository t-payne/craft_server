#pragma once
#include "Command.h"
#include <string>

using namespace std;

class ChunkCommand:public Command
{
public:
	ChunkCommand(string chunkMessage );
	void execute()override;





private:
	int p, q, key;

};