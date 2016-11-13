#pragma once
#include "GameManager.h"

namespace nmh{
	class ManagerFactory
	{
		GameManager *Game;
	public:
		ManagerFactory();
		~ManagerFactory();
		GameManager *GetGameManager();
	};
}

