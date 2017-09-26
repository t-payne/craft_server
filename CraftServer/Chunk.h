#pragma once
#include <map>
#include <tuple>
using namespace std;

enum BlockType
{
	AIR,
	GRASS,
	SAND,
	STONE,
	BRICK,
	WOOD,
	CEMENT,
	DIRT,
	PLANK,
	SNOW,
	GLASS,
	COBBLE,
	LIGHT_STONE,
	DARK_STONE,
	CHEST,
	LEAVES,
	TALL_GRASS,
	YELLOW_FLOWER,
	RED_FLOWER,
	PURPLE_FLOWER,
	SUN_FLOWER,
	WHITE_FLOWER,
	BLUE_FLOWER,
	COLOR_00,
	COLOR_01,
	COLOR_02,
	COLOR_03,
	COLOR_04,
	COLOR_05,
	COLOR_06,
	COLOR_07,
	COLOR_08,
	COLOR_09,
	COLOR_10,
	COLOR_11,
	COLOR_12,
	COLOR_13,
	COLOR_14,
	COLOR_15,
	COLOR_16,
	COLOR_17,
	COLOR_18,
	COLOR_19,
	COLOR_20,
	COLOR_21,
	COLOR_22,
	COLOR_23,
	COLOR_24,
	COLOR_25,
	COLOR_26,
	COLOR_27,
	COLOR_28,
	COLOR_29,
	COLOR_30,
	COLOR_31
};

class Chunk
{
public:
	Chunk();
	Chunk(int p, int q);
	void insertBlock(int x, int y, int z, BlockType item);


private:
	map<tuple<int, int, int>, BlockType> blocks;
	int p;
	int q;


};