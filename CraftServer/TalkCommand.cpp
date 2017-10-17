#include "TalkCommand.h"
#include "Client.h"
#include <iostream>
using namespace std;

TalkCommand::TalkCommand(Client& client,string message):message(message),client(client)
{
	
		
}
void TalkCommand::execute()
{
	//cout << message << endl;
	if (message[0] == '/')
	{

	}
}