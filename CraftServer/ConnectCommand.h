#pragma once
#include "Command.h"
#include "Model.h"
#include "Client.h"
#include <string>

using namespace std;

class ConnectCommand :public Command
{
public:
	ConnectCommand(Model& model,Client& client ); //connectcommand object into the queue server puts command as soon as client connects. similar to onconnect
	void execute() override;


private:
	Model& model;
	Client& client;
};