#include "stdafx.h"
#include "GFleet.h"


GFleet::GFleet(void)
{
	for (int i = 0; i < 5; i++)
		fl[i] = NULL;
	shipcount[0] = 0;
	maxshipcount[0] = 0;
	aliveships = 0;
}

GFleet::GFleet(int one, int two, int three, int four)
{
	GFleet();
	fl[1] = new GShip[one];
	maxshipcount[1] = one;
	shipcount[1] = 0;
	fl[2] = new GShip[two];
	maxshipcount[2] = two;
	shipcount[2] = 0;
	fl[3] = new GShip[three];
	maxshipcount[3] = three;
	shipcount[3] = 0;
	fl[4] = new GShip[four];
	maxshipcount[4] = four;
	shipcount[4] = 0;
}	

GFleet::~GFleet(void)
{
	for (int i = 1; i < 5; i++)
		if (fl[i] != NULL)
			delete[] fl[i];
}

int GFleet::Attack(CPoint p)
{
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < shipcount[i]; j++)
		{
			int res = fl[i][j].Beat(p);
			switch (res)
			{
				case BEAT :
					return BEAT;
				case DEAD :
					if (--aliveships)
						return DEAD;
					else
						return ALLDEAD;
			}
		}
}

int GFleet::Attack(int x, int y)
{
	return Attack(CPoint(x,y));
}

int GFleet::AddShip(GShip sh)
{
	int sl = sh.Length();
	if (maxshipcount[sl] <= shipcount[sl])
		return BAD;
	CPoint *out; 
	sh.GetPositions(out);
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < shipcount[i]; j++)
		{
			if (fl[i][j].Crosses(out, sl))
			{
				delete[] out;
				return BAD;
			}
		}
	delete[] out;
	fl[sl][shipcount[sl]++] = sh;
	aliveships++;
	return GOOD;
}

int GFleet::ShipsCount()
{
	int res = 0;
	for (int i = 1; i < 5; i++)
		res += shipcount[i];
	return res;
}

int GFleet::AliveCount()
{
	return aliveships;
}

bool GFleet::ShipsOnPanel(int x, int y)
{
	for (int i = 1; i < 5; i++)
		for (int j = 0; j < shipcount[i]; j++)
			if (!(fl[i][j].IsInPanel(x,y)))
				return false;
	return true;
}