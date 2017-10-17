#include "DisconnectCommand.h"
#include "Client.h"
#include "TalkCommand.h"
#include <iostream>
using namespace std;
void DisconnectCommand::execute()
{
	/*string query{
		"select rowid, x, y, z, w from block where "
		"p = " + to_string(p) + " and q = " + to_string(q) +
		"and rowid > " + to_string(key) + ";"
	};*/ //Taylor put this here
	//client=model.getClient();
	
	model.remove(client);
	model.deleteFromVector(client);
}
DisconnectCommand::DisconnectCommand(Model& model, Client& client):model(model),client(client) // not sure if model is needed
{
	cout << client.nick << " has disconnected from the server" << endl;
}