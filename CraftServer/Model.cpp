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

}
void Model::createTable()
{
	sqlite3 *db;
	int rc; // This line
	string sqlTable1, sqlTable2; // This line
	rc = sqlite3_open("craft.db", &db);

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
	for (auto query : queries)
	{
		/* Execute SQL statement */
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);
		
	}
		
	sqlite3_close(db);

}
void Model::commit()
{
	last_commit = get_time::now();
	
	
}