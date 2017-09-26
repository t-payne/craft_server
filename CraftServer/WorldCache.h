#pragma once
#include <map>
#include <queue>
#include <tuple>
#include "Chunk.h"

using namespace std;

class WorldCache
{
public:
	WorldCache(int seed, int cache_size);
	WorldCache();
	//~WorldCache();
	Chunk getChunk(int p, int q);


private:
	void insertChunk(tuple<int, int> coords, Chunk chunk);
	map <tuple<int, int>, Chunk>cache; // 
	Chunk createChunk(int p, int q);
	int cache_size;
	int noise_seed;
	queue<tuple<int, int>>cacheQueue; //remembers which chunk has been in the cache the longest
};

template<typename WorldFunc>
void create_world(int p, int q, WorldFunc func, void *arg);

