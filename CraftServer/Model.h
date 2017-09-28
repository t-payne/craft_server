#pragma once
#include "world.h"
#include "Server.h"
#include <queue>
#include <thread>
#include "sqlite3.h"
#include <string>
#include <time.h>
#include <iostream>
#include <chrono>

using namespace std; 
using get_time = chrono::steady_clock;

class Model
{
public:
	Model();
	//~Model();
	void start();
	static void run();
	void createTable();
	void commit();
private:
	World world;
	Server server;
	chrono::time_point<chrono::steady_clock> last_commit;
	//queue<
};

