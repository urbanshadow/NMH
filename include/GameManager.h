#pragma once
#include <cstdio>
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
#include <sftd.h>

#include "../build/geonms_ttf.h"
#include "Galaxy.h"
#include "Manager.h"

#define STEREO3D true

namespace nmh{

	class ManagerFactory;

	class GameManager :
		public Manager
	{
		sftd_font* Font;
	public:
		GameManager(ManagerFactory* managerFactory);
		~GameManager();
		int Start();
	};
}

