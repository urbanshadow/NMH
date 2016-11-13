#include "..\include\ManagerFactory.h"

using namespace nmh;

ManagerFactory::ManagerFactory()
{
	Game = 0;
}

ManagerFactory::~ManagerFactory()
{
	delete Game;
}

GameManager* ManagerFactory::GetGameManager()
{
	if (Game == 0) Game = new GameManager(this);
	return Game;
}
