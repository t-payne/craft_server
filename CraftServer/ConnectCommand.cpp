#include "ConnectCommand.h"


ConnectCommand::ConnectCommand(Model& model, Client& client):model(model),client(client)
{
	
}
void ConnectCommand::execute()
{
	client.nick = "Guest" + client.id;
	client.position = make_tuple(0, 0, 0, 0, 0);
	client.send(client.createPacket("U", client.id, client.position));
}