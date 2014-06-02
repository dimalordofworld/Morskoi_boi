#pragma once
#include "GShip.h"

#define GOOD 1
#define BAD 0
#define ERROR -1

class GFleet
{
	GShip* fl[5];
	int shipcount[5];
	int maxshipcount[5];
	int aliveships;

public:
	GFleet(void);
	GFleet(int one, int two, int three, int four);
	~GFleet(void);

	int Attack(CPoint p);
	int Attack(int x, int y);
	int AddShip(GShip sh);
	int ShipsCount();
	int AliveCount();
	bool ShipsOnPanel(int x, int y);
};

