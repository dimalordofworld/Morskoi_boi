#pragma once
#include "GPlayPanel.h"

class GPlayer
{
	GPlayPanel panel;
	bool avto;
	int** attacked;
	int situation;


public:
	GPlayer(void);
	GPlayer(int X, int Y, int one, int two, int three, int four);
	~GPlayer(void);

	int Attack(GPlayer pl, CPoint p);
	int AttackAuto(GPlayer pl);
	int NotAttackedPos();
	void ChangeAuto();
	int AliveCount();
};

