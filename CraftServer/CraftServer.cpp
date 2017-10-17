// CraftServer.cpp : Defines the entry point for the console application.

#include "world.h"
#include "Server.h"
#include "Model.h"
#include "DisconnectCommand.h"
#include "Client.h"

int main()
{
	Model mod;
	mod.commit();
	Server server(mod);
	Client l;
	mod.remove(l);

	/*World hello;
	hello.getChunk(20, 11);
	Server server;
	server.run();*/
	
    return 0;
}

