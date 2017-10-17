#pragma once
#include "Command.h"
#include <string>
#include "Model.h"
#include "Client.h"

using namespace std;

class DisconnectCommand :public Command
{
public:
	DisconnectCommand(Model& model, Client& client); // string message ?
	void execute() override;
	DisconnectCommand(string message);

private:
	//int p, q, key; // ?
	Client& client;
	Model& model;
	string message;
};

