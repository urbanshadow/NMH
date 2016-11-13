#include "ManagerFactory.h"

int main(int argc, char **argv)
{
	nmh::ManagerFactory factory;
	nmh::GameManager gman(&factory);
	return gman.Start();
}