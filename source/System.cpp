#include "..\include\System.h"

using namespace nmh;

Planet System::ExplorePlanet(u8 planet)
{
	u32 s = Seed + planet % MAXPLANETS;

	std::mt19937 rng(s);
	std::uniform_int_distribution<u32> dist;

	return Planet {s, (u16) (dist(rng) % SCENESIZE/4), (u16) (dist(rng) % SCENESIZE/4), (u16) (dist(rng) % SCENESIZE) };
}

Moon System::ExploreMoon(u8 moon)
{
	u32 s = Seed + moon % MAXMOONS;

	std::mt19937 rng(s);
	std::uniform_int_distribution<u32> dist;

	return Moon{ s, (u16)(dist(rng) % MAXPLANETS), (u16) (dist(rng) % SCENESIZE/4) };
}

System::System(u32 seed) : ProceduralContent<u32>(seed)
{
	details = (u16) Dist(Rng);
	details += (details & 0x000F) < 3 ? 3 : 0;
}

System::~System()
{
}

u8 System::GetNumPlanets()
{
	return details & 0x000F;
}
