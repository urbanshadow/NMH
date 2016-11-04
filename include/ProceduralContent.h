#pragma once

#include <3ds.h>
#include <random>

namespace nmh {
	template <typename T = u16> class ProceduralContent
	{
	protected:
		T Seed;
		std::mt19937 Rng;
		std::uniform_int_distribution<T> Dist;
	public:
		ProceduralContent(T seed) : Rng(seed), Dist() { Seed = seed; };
		~ProceduralContent() {};
		T GetSeed() { return Seed; };
	};
}