#pragma once

#define ALLDEAD 3
#define DEAD 2
#define BEAT 1
#define NOBEAT 0
#define ERROR -1

class GShip
{
	int length;
	CPoint start;
	bool vertical;
	int* alive;
	int alivelength;
public:
	GShip(void);
	GShip(int x, int y, int len, bool vert);
	GShip(CPoint p, int len, bool vert);
	~GShip(void);

	int GetPositions(CPoint* &out);
	int Beat(CPoint p);
	bool IsDead();
	int Length();
	bool IsInPanel(int x, int y);
	bool Crosses(GShip sh);
	bool Crosses(CPoint *p, int len);
};

