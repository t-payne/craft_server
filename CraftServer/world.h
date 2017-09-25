#include <tuple>
#include <map>
#ifndef _world_h_
#define _world_h_

using namespace std;

class World
{
public:
	World(int seed,int cache_size);
	World();
	//~World();
	map<tuple<int, int, int>, int>createChunk(int p, int q);

private:
	map<tuple<int, int>, map<tuple<int, int, int>, int>>cache;
	int cache_size;
	int seed1;
	map<tuple<int, int>, map<tuple<int, int, int>, int>>getchunk(int p, int q);




};
typedef void (*world_func)(int, int, int, int, void *);
template<typename WorldFunc>
void create_world(int p, int q, WorldFunc func, void *arg);

#endif
