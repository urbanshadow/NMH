#include "..\include\System.h"

using namespace nmh;

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
