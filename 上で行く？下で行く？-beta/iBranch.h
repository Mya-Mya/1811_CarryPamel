#pragma once
#include"TurnDirection.h"
#include<string>
using namespace std;


class Point;

class iBranch
{
public:
	virtual bool canTurn(Point*nowpoint, TurnDirection td)=0;
	virtual Point* turn(Point*nowpoint, TurnDirection td)=0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual string getName() = 0;
};

