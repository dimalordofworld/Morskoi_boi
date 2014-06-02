#include "stdafx.h"
#include "GShip.h"

GShip::GShip(void)
{
	GShip(0, 0, 1, true);
}

GShip::GShip(int x, int y, int len, bool vert)
{
	CPoint p(x,y);
	GShip(p, len, vert);
}

GShip::GShip(CPoint p, int len, bool vert)
{
	start = p;
	length = len;
	vertical = vert;
	alive = new int[length];
	for (int i = 0; i < length; i++)
		alive[i] = 1;
	alivelength = length;
}

GShip::~GShip(void)
{
	delete[] alive;
}

int GShip::GetPositions(CPoint* &out)
{
	out = new CPoint[length];
	for (int i = 0; i < length; i++)
		out[i] = vertical ? start + CPoint(0, i) : start + CPoint(i, 0);
	return length;
}

int GShip::Beat(CPoint p)
{
	for (int i = 0; i < length; i++)
	{
		int x = vertical ? start.x : start.x + i;
		int y = vertical ? start.y + i : start.y;
		if ((p.x == x) && (p.y == y))
		{
			if (alive[i])
			{
				alive[i] = 0;
				if (--alivelength)
					return BEAT;
				return DEAD;
			}
			return ERROR;
		}
	}
	return NOBEAT;
}

bool GShip::IsDead()
{
	return (alivelength <= 0); 
}

int GShip::Length()
{
	return length;
}

bool GShip::IsInPanel(int x, int y)
{
	if (vertical ? start.x + 1 : start.x + length > x)
		return false;
	if (vertical ? start.y + length : start.y + 1 > y)
		return false;
	return true;
}

bool GShip::Crosses(GShip sh)
{
	CPoint tmp, *out; 
	int sl = sh.GetPositions(out); 
	for (int i = 0; i < length; i++)
	{
		tmp = vertical ? start + CPoint(0, i) : start + CPoint(i, 0);
		for (int j = 0; j < sl; j++)
			if (out[j] == tmp)
			{
				delete[] out;
				return true;
			}
	}
	delete[] out;
	return false;
}

bool GShip::Crosses(CPoint *p, int len)
{
	for (int i = 0; i < length; i++)
	{
		CPoint tmp = vertical ? start + CPoint(0, i) : start + CPoint(i, 0);
		for (int j = 0; j < len; j++)
			if (p[j] == tmp)
				return true;
	}
	return false;
}
