#include "DataCommand.h"

void DataCommand::execute()
{
	string query{
		"select rowid, x, y, z, w from block where "
		"p = " + to_string(p) + " and q = " + to_string(q) +
		"and rowid > " + to_string(key) + ";"
	};
}