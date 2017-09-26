#include "Chunk.h"

Chunk::Chunk(int p, int q)
	:p(p), q(q)
{

}

Chunk::Chunk()
{
	p = 0;
	q = 0;
}

void Chunk::insertBlock(int x, int y, int z, BlockType item)
{
	blocks[make_tuple(x, y, z)] = item;
}
