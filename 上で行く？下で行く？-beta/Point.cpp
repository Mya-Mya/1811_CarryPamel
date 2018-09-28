#include "Point.h"
#include "DxLib.h"


void Point::rgstLink(Point *link, TrafficState ts)
{
	MyLink = link;
	MyTS = ts;
	switch (ts) {
	case Green:
		LineColor = GetColor(120, 255, 0);
		break;
	case Orange:
		LineColor = GetColor(255, 173, 86);
		break;
	case Red:
		LineColor = GetColor(255, 30, 0);
		break;
	case Winered:
		LineColor = GetColor(104, 15, 0);
		break;
	case TrafficState_None:
		LineColor = GetColor(50, 50, 50);
		break;
	}
}

void Point::rgstrIBranch(iBranch * you)
{
	MyBranch = you;
}

void Point::init()
{
	LineColor = GetColor(210, 160, 220);
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
	return MyBranch->getX();
}

int Point::getY()
{
	return MyBranch->getY();
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
		DrawLine(getX(), getY(), MyLink->getX(), MyLink->getY(),
		(IFScreenTS ? LineColor : GetColor(50, 50, 50)), 4);

	DrawCircle(getX(), getY(), 4, GetColor(0, 0, 0), TRUE);
}
