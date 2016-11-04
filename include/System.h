#pragma once

#include "Galaxy.h"

#define MAXPLANETS 16
#define MAXMOONS 6
#define SCENESIZE 65536

namespace nmh {

	typedef struct {
		u32 Seed;
		u16 X;
		u16 Y;
		u16 Radius;		
	}Planet;

	typedef struct {
		u32 Seed;
		u16 Planet;
		u16 Radius;
	}Moon;

	class System :
		public ProceduralContent<u32>
	{
		
		u16 details;
		Planet *planets;
		Moon *moons;
	public:
		Planet ExplorePlanet(u8 planet);
		Moon ExploreMoon(u8 moon);
		System(u32 seed);
		virtual ~System();
		u8 GetNumPlanets();
		
	};
}

