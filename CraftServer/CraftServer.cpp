// CraftServer.cpp : Defines the entry point for the console application.

#include "world.h"
#include "Server.h"

int main()
{
	World hello;
	hello.getChunk(20, 11);
	Server server;
	server.run();
    return 0;
}

