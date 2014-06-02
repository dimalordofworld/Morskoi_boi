#include "stdafx.h"
#include "GPlayPanel.h"


GPlayPanel::GPlayPanel(void)
{
	GPlayPanel(10, 10);
}

GPlayPanel::GPlayPanel(int X, int Y)
{
	lenX = X;
	lenY = Y;
	attacked = new int*[lenX];
	for (int i = 0; i < lenX; i++)
	{
		attacked[i] = new int[lenY];
		for (int j = 0; j < lenY; j++)
			attacked[i][j] = 0;
	}
}

GPlayPanel::GPlayPanel(int X, int Y, GFleet fl)
{
	GPlayPanel(X, Y);
	if (fl.ShipsOnPanel(lenX, lenY))
		fleet = fl;
}

GPlayPanel::GPlayPanel(int X, int Y, int one, int two, int three, int four)
{
	GPlayPanel(X, Y);
	fleet = GFleet(one, two, three, four);
}

GPlayPanel::~GPlayPanel(void)
{
	for (int i = 0; i < lenX; i++)
		delete[] attacked[i];
	delete[] attacked;
}

bool GPlayPanel::Attacked(CPoint p)
{
	return (attacked[p.x][p.y] == 1); 
}

int GPlayPanel::Attack(CPoint p)
{
	int res = fleet.Attack(p);
}

int GPlayPanel::Attack(int x, int y)
{
	return Attack(CPoint(x,y));
}

int GPlayPanel::AddShip(GShip sh)
{
	if (sh.IsInPanel(lenX,lenY))
		return fleet.AddShip(sh);
	return BAD;
}

int GPlayPanel::ShipsCount()
{
	return fleet.ShipsCount();
}

int GPlayPanel::AliveCount()
{
	return fleet.AliveCount();
}

CPoint GPlayPanel::GetDim()
{
	return CPoint(lenX, lenY);
}

int GPlayPanel::NotAttackedPos()
{
	int res = lenX * lenY;
	for (int i = 0; i < lenX; i++)
		for (int j = 0; j < lenY; j++)
			res -= attacked[i][j]; 
	return res;
}