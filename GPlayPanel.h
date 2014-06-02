#pragma once
#include "GFleet.h"

class GPlayPanel
{
	GFleet fleet;
	int lenX;
	int lenY;
	int** attacked;

public:
	GPlayPanel(void);
	GPlayPanel(int X, int Y);
	GPlayPanel(int X, int Y, GFleet fl);
	GPlayPanel(int X, int Y, int one, int two, int three, int four);
	~GPlayPanel(void);

	bool Attacked(CPoint p);
	int Attack(CPoint p);
	int Attack(int x, int y);
	int AddShip(GShip sh);
	int ShipsCount();
	int AliveCount();
	CPoint GetDim();
	int NotAttackedPos();
};

