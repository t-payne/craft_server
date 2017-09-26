#include "WorldCache.h"
#include "noise.h"
#include "world.h"
using namespace std;

WorldCache::WorldCache(int seed, int cache_size):noise_seed(seed), cache_size(cache_size)
{

}

WorldCache::WorldCache()
{
	noise_seed = 0;
	cache_size = 64;
}

Chunk WorldCache::getChunk(int p, int q)
{
	auto chunkTuple = make_tuple(p, q);
	if (cache.find(chunkTuple) != cache.end())
	{
		return cache[chunkTuple];
	}

	Chunk newChunk = createChunk(p, q);
	insertChunk(chunkTuple, newChunk);
	return newChunk;
}

Chunk WorldCache::createChunk(int p, int q)
{
	seed(noise_seed);
	Chunk result(p,q);
	auto func = [&](int x, int y, int z, int w, void* arg) {
		result.insertBlock(x, y, z, (BlockType) w);
	};

	create_world(p, q, func, nullptr);
	return result;
}

void WorldCache::insertChunk(tuple<int, int> coords, Chunk chunk)
{
	cache[coords] = chunk;
	cacheQueue.push(coords);

	if ((int)cacheQueue.size() > cache_size)
	{
		cacheQueue.pop();
	}
}