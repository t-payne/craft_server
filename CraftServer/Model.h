#pragma once
#include "world.h"
#include <queue>
//#include <thread>
#include "sqlite3.h"
#include <memory>
//#include <Windows.h>
#include <string>
//#include <time.h>
//#include <iostream>
#include <chrono>
//#include <tuple>
//#include "Command.h"
//#include "Client.h"
//#include "Model.h"
#include <tuple>
class Client;
class Command;


using namespace std; 
using get_time = chrono::steady_clock;
const int commit_interval = 5;
const tuple<int, int, int, int, int> spawnPoint = { 0,0,0,0,0 };


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
	static void addCommand(unique_ptr<Command> command);
	//static void getNextId();
	static Client& getClient(int);
	static void remove(Client&);//I
	static int& search(Client&);//I
	static void deleteFromVector(Client&);// I
	static void connect(Client&);//I

private:
	World world;
	//Server server;
	static chrono::time_point<chrono::steady_clock> last_commit;
	static queue<unique_ptr<Command>> commands;
	static sqlite3 *db;
	static vector<Client> &clients;

};

