
#include "world.h"
World::World(int seed, int cache_size):world_cache(seed, cache_size)
{
	
}

World::World()
{
	world_cache = WorldCache();
}


Chunk World::getChunk(int p, int q)
{
	return world_cache.getChunk(p,q);
}


