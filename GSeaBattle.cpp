#include "stdafx.h"
#include "GSeaBattle.h"


GSeaBattle::GSeaBattle(void)
{
	GSeaBattle(10, 10, 4, 3, 2, 1);
}

GSeaBattle::GSeaBattle(int x, int y, int one, int two, int three, int four)
{
	move = 1;
	pl1 = GPlayer(x, y, one, two, three, four);
	pl2 = GPlayer(x, y, one, two, three, four);
}

GSeaBattle::~GSeaBattle(void)
{
}

int GSeaBattle::Move1(CPoint p)
{
	if (move == 1)
	{
		move = 2;
		return pl1.Attack(pl2, p);
	}
	return ERROR;
}

int GSeaBattle::Move2(CPoint p)
{
	if (move == 2)
	{
		move = 1;
		return pl2.Attack(pl1, p);
	}
	return ERROR;
}

void GSeaBattle::ChangeAvto(int pl)
{
	if (pl == 1)
		pl1.ChangeAuto();
	else
		pl2.ChangeAuto();
}
