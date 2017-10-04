#include "CommandFactory.h"
#include "ChunkCommand.h"

CommandFactory::CommandFactory()
{

}
Command& CommandFactory::createCommand(string message)
{
//	ChunkCommand me;
	switch (message[0])
	{
	case 'A':

		break;
	case 'B':

		break;
	case 'C':
//		ChunkCommand chunkObject;
		break;
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
	case 'S':

		break;
	case 'T':
		break;
	case 'E':

		break;
	case 'V':

		break;
	case 'U':
		break;
	}
	
}