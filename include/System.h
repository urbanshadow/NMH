#pragma once

#include "Galaxy.h"

namespace nmh {
	class System :
		public ProceduralContent<u32>
	{
		u16 details;
	public:
		System(u32 seed);
		virtual ~System();
		u8 GetNumPlanets();
	};
}

