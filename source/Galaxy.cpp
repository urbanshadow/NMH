#include "..\include\Galaxy.h"

using namespace nmh;

Galaxy::Galaxy(u32 seed) : ProceduralContent<u32>(seed)
{
}

Galaxy::~Galaxy()
{
}

Star nmh::Galaxy::ExploreStar(u16 chunkX, u16 chunkY, u8 star)
{
	u32 s = Seed + chunkX * CHUNKS * CHUNKSTARS + chunkY * CHUNKSTARS + star % CHUNKSTARS;
	
	std::mt19937 rng(s);
	std::uniform_int_distribution<u32> dist;

	return Star { s, (u16) (dist(rng) % CHUNKSIZE), (u16) (dist(rng) % CHUNKSIZE) };
}
