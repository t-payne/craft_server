#pragma once
#include <string>
#include "Client.h"
#include <algorithm>
using namespace std;

class Helper
{
public:
	Helper(Client,string topic);
	void choice(string choice);

private:
	string topic;
	Client client;


};