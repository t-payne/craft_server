#include <Windows.h>
//#include "world.h"
#include <thread>
#include <time.h>
#include <iostream>
#include <tuple>
#include "Command.h"
#include "Client.h"
#include "Model.h"


Model::Model()
{
	
}
void Model::start()
{
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)run, NULL, NULL, NULL);
}
void Model::run()
{
	int rc;
	rc = sqlite3_open("craft.db", &db);
	createTables();
	while (1)
	{
		auto currentTime=get_time::now();
		auto timeElapsed = chrono::duration_cast<chrono::seconds>(currentTime - last_commit).count();
		if (timeElapsed > commit_interval)
		{
			commit();
		}
		executeCommand();
	}
}
Client& Model::getClient(int i)
{
	return clients[i];
}

void Model::execute(string query)
{
	int rc;
	beginTransaction();
	rc = sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);
}
void Model::executeCommand()
{
	commands.front()->execute();
	commands.pop();
}
void Model::addCommand(unique_ptr<Command> cmd_ptr)
{
	commands.push(make_unique<Command>(cmd_ptr));
}
void Model::createTables()
{
	int rc;
	/* Create SQL statement */
	vector<string>queries  {"CREATE TABLE IF NOT EXISTS block("  \
		"p int               NOT NULL,"
		"q int				 NOT NULL,"
		"x int               NOT NULL,"
		"y int				 NOT NULL,"
		"z int               NOT NULL,"
		"w int				 Not NULL);",
		"create unique index if not exists block_pqxyz_idx on "
		"    block (p, q, x, y, z);",
		"CREATE TABLE IF NOT EXISTS light ("
		"    p int not null,"
		"    q int not null,"
		"    x int not null,"
		"    y int not null,"
		"    z int not null,"
		"    w int not null"
		");", 
		"create unique index if not exists light_pqxyz_idx on "
		"    light (p, q, x, y, z);",
		"create table if not exists sign ("
		"    p int not null,"
		"    q int not null,"
		"    x int not null,"
		"    y int not null,"
		"    z int not null,"
		"    face int not null,"
		"    text text not null"
		");",
		"create index if not exists sign_pq_idx on sign (p, q);",
		"create unique index if not exists sign_xyzface_idx on "
		"    sign (x, y, z, face);",
		"create table if not exists block_history ("
		"   timestamp real not null,"
		"   user_id int not null,"
		"   x int not null,"
		"   y int not null,"
		"   z int not null,"
		"   w int not null"
		");",

};
	beginTransaction();
	for (auto query : queries)
	{
		/* Execute SQL statement */
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);
		
	}
	commit();
	sqlite3_close(db);

}
void Model::commit()
{
	last_commit = get_time::now();
	sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
}
void Model::beginTransaction()
{
	sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

}
