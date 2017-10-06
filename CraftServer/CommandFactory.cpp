#include "CommandFactory.h"
#include "ChunkCommand.h"
#include "TalkCommand.h"

CommandFactory::CommandFactory()
{

}
unique_ptr<Command> CommandFactory::createCommand(string message)
{
//	ChunkCommand me;
	switch (message[0])
	{
	case 'A':

		break;
	case 'B':

		break;
	case 'C': {
		ChunkCommand chunkObject(message);
		break; }
	case 'D':

			break;
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
		TalkCommand talk(message);
		talk.execute;
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