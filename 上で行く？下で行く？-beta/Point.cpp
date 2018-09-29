#include "Point.h"
#include "DxLib.h"


void Point::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::rgstLink(Point *link, TrafficState ts)
{
	MyLink = link;
	MyTS = ts;
	switch (ts) {
	case Green:
		lineColWithTS = GetColor(120, 255, 0);
		break;
	case Orange:
		lineColWithTS = GetColor(255, 173, 86);
		break;
	case Red:
		lineColWithTS = GetColor(255, 30, 0);
		break;
	case Purple:
		lineColWithTS = GetColor(158, 28, 191);
		break;
	case TrafficState_None:
		break;
	}
}

void Point::rgstrIBranch(iBranch * you)
{
	MyBranch = you;
}

void Point::init()
{
	lineColWithTS = GetColor(111, 176, 21);
	lineColWithNoTS = GetColor(150, 150, 150);
}


void Point::setScreenTS(bool IFScreenTS)
{
	this->IFScreenTS = IFScreenTS;
}


iBranch * Point::getBranch()
{
	return MyBranch;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

bool Point::canTurn(TurnDirection td)
{
	return MyBranch->canTurn(this,td);
}

Point * Point::turn(TurnDirection td)
{
	if (td == TurnDirection_None)return this;
	return MyBranch->turn(this,td);
}

Point * Point::getLink()
{
	return MyLink;
}


TrafficState Point::getTS()
{
	return MyTS;
}

void Point::drawOnMap()
{
	if (MyLink != nullptr)
		DrawLine(x, y, MyLink->getX(), MyLink->getY(),
		(IFScreenTS ? lineColWithTS : lineColWithNoTS), 7);
}
