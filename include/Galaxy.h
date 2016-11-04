#pragma once

#include "ProceduralContent.h"
#include "System.h"

#define CHUNKS 65536
#define CHUNKSIZE 512
#define CHUNKSTARS 64

namespace nmh {

	typedef struct {
		u32 seed;
		u16 localX;
		u16 localY;
	}Star;

	class Galaxy : public ProceduralContent<u32>
	{
	public:
		Galaxy(u32 seed);
		virtual ~Galaxy();
		Star ExploreStar(u16 chunkX, u16 chunkY, u8 star);
	};
}

