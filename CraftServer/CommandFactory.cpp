#include "CommandFactory.h"
#include "ChunkCommand.h"
#include "TalkCommand.h"
#include "DisconnectCommand.h"
#include <vector>
#include <sstream>

CommandFactory::CommandFactory(Client& client):client(client)
{
	//client = client1;
}
unique_ptr<Command> CommandFactory::createCommand(Client& client,string message) //message
{
	char character = search(message);
	
	switch (message[0]) //message[0]
	{
	case 'A':

		break;
	case 'B':

		break;
	case 'C': {
		ChunkCommand chunkObject(message);
		break; }
	case 'D': {
		DisconnectCommand disconnect(message);
		disconnect.execute();
		break; }
	case 'K':
		break;
	case 'L':

		break;
	case 'P':

		break;
	case 'R':

		break;
	case 'S': {

		break;
	}
	case 'T': {
		TalkCommand talk(client, message);
		talk.execute();
		break;
	}
	case 'E':

		break;
	case 'V':

		break;
	case 'U':
		break;
	}
	return make_unique<ChunkCommand>(ChunkCommand(message));
}
char CommandFactory::search(string message)
{
	char found;
	istringstream iss(message);
	vector<string>messages;
	do
	{
		iss >> message;
		messages.push_back(message);
	} while (iss);

	if (messages[0].find("A"))
	{
		found = 'A';
	}
	if (messages[0].find("B"))
	{
		found = 'B';
	}

	return found;

}