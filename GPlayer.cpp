#include "stdafx.h"
#include "GPlayer.h"

#define UNDEFINED 0

GPlayer::GPlayer(void)
{
	GPlayer(10, 10, 4, 3, 2, 1);
}

GPlayer::GPlayer(int X, int Y, int one, int two, int three, int four)
{
	panel = GPlayPanel(X, Y, one, two, three, four);
	avto = false;
	attacked = new int*[X];
	for (int i = 0; i < X; i++)
	{
		attacked[i] = new int[Y];
		for (int j = 0; j < Y; j++)
			attacked[i][j] = 0;
	}
	situation = UNDEFINED;
}

GPlayer::~GPlayer(void)
{
	CPoint p = panel.GetDim();
	for (int i = 0; i < p.x; i++)
		delete[] attacked[i];
	delete[] attacked;
}

int GPlayer::Attack(GPlayer pl, CPoint p)
{
	if ((avto) || (situation == BEAT))
		return AttackAuto(pl);
	int nmb = NotAttackedPos();
	// random place 

}

int GPlayer::AttackAuto(GPlayer pl)
{

}

int GPlayer::NotAttackedPos()
{
	return panel.NotAttackedPos();
}

void GPlayer::ChangeAuto()
{
	avto = !avto;
}

int GPlayer::AliveCount()
{
	return panel.AliveCount();
}



