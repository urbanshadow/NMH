#include "..\include\GameManager.h"
#include "..\include\ManagerFactory.h"

using namespace nmh;

GameManager::GameManager(ManagerFactory* managerFactory) : Manager(managerFactory)
{
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
	sf2d_set_3D(STEREO3D);
	sftd_init();
}

GameManager::~GameManager()
{
	sftd_free_font(Font);
	sftd_fini();
	sf2d_fini();
}

int GameManager::Start()
{
	Font = sftd_load_font_mem(geonms_ttf, geonms_ttf_size);
	char line[150];

	nmh::Galaxy g(1);
	nmh::Star s = g.ExploreStar(0, 0, 0);
	nmh::System sy(s.seed);
	nmh::Planet p = sy.ExplorePlanet(sy.GetNumPlanets() - 2);

	sprintf(line, "Galaxy %lu\n System %lu at %u:%u (%u,%u)\n  Planets %u\n  Planet %lu\n   Radius %u", g.GetSeed(), s.seed, 0, 0, s.localX, s.localY, sy.GetNumPlanets(), p.Seed, p.Radius);

	while (aptMainLoop())
	{
		hidScanInput();
		u16 kHeld = hidKeysHeld();
		if (kHeld & KEY_START) break;
		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sftd_draw_text(Font, 0, 0, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 20, line);
		sf2d_end_frame();

		sf2d_swapbuffers();
	}

	return 0;
}
