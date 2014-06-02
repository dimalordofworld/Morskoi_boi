#pragma once
#include "GPlayer.h"

class GSeaBattle
{
	GPlayer pl1,pl2;
	int move;

public:
	GSeaBattle(void);
	GSeaBattle(int x, int y, int one, int two, int three, int four);
	~GSeaBattle(void);

	int Move1(CPoint p);
	int Move2(CPoint p);
	void ChangeAvto(int pl);
};

