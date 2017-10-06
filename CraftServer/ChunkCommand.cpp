#include "ChunkCommand.h"
#include <sstream>
#include <vector>
#include "Model.h"

ChunkCommand::ChunkCommand(string chunkMessage)
{
	//will be in the format C,p,q ,Key
	stringstream ss(chunkMessage);

	ss >> p;
	ss >> q;
	ss >> key;
}

void ChunkCommand::execute()
{
	vector<string> packets;
	string query{
		"select rowid, x, y, z, w from block where "
		"p = " + to_string(p) + " and q = " + to_string(q) +
		"and rowid > " + to_string(key) + ";"
	};

	// auto rows = Model::execute(query); // results from the database
	
}