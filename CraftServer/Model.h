#pragma once
#include "world.h"
//#include "Server.h"
#include <queue>
#include <thread>
#include "sqlite3.h"
#include <Windows.h>
#include <string>
#include <time.h>
#include <iostream>
#include <chrono>
#include "Command.h"
#include "Model.h"

using namespace std; 
using get_time = chrono::steady_clock;
const int commit_interval = 5;


class Model
{
public:
	Model();
	//~Model();
	void start();
	static void run();
	static void createTables();
	static void commit();
	static void beginTransaction();
	static void execute(string query);
	static void executeCommand();
	static void addCommand(Command& command);
private:
	World world;
	//Server server;
	static chrono::time_point<chrono::steady_clock> last_commit;
	static queue<Command>commands;
	static sqlite3 *db;

};

