#include "Branch.h"
#include "Point.h"
#include"DxLib.h"

Branch::Branch(int x,int y)
{
	this->x = x;
	this->y = y;
	for (int i = 0; i < 4; i++)point[i] = nullptr;
}


Branch * Branch::makePoint(int branchNum)
{
	if (branchNum < 0 || 3 < branchNum)return nullptr;
	Point *newPoint= new Point();
	newPoint->init();
	newPoint->rgstrIBranch(this);
	point[branchNum] = newPoint;
	return this;
}

Point * Branch::getPoint(int branchNum)
{
	if (branchNum < 0 || 3 < branchNum)return nullptr;
	return point[branchNum];
}


void Branch::setWhatToDraw(MapWhatToDraw WhatToDraw)
{
	this->WhatToDraw = WhatToDraw;
}


void Branch::rgstName(string name, string namereading)
{
	this->Name = name;
	this->NameReading = namereading;
}

void Branch::setScreenTS(bool IfScreenTS)
{
	for (int i = 0; i < 4; i++) {
		if (point[i] != nullptr)point[i]->setScreenTS(IfScreenTS);
	}
}

bool Branch::canTurn(Point *nowpoint, TurnDirection td)
{
	int nowpointnum = -1;
	for (int i = 0; i < 4; i++) {
		if (point[i] == nowpoint) nowpointnum = i;
	}
	return point[(4+nowpointnum+td)%4]!=nullptr;
}

Point * Branch::turn(Point *nowpoint, TurnDirection td)
{
	int nowpointnum = -1;
	for (int i = 0; i < 4; i++) {
		if (point[i] == nowpoint) nowpointnum = i;
	}
	return point[(4 + nowpointnum + td) % 4]->getLink();
}

int Branch::getX()
{
	return x;
}

int Branch::getY()
{
	return y;
}

string Branch::getName()
{
	return Name;
}

void Branch::drawOnMap()
{
	if (WhatToDraw == MapWhatToDraw::ROADS_DRAW) {
		for (int i = 0; i < 4; i++) {
			if (point[i] != nullptr)point[i]->drawOnMap();
		}
	}
	if (WhatToDraw == MapWhatToDraw::SPOTNAMES_DRAW) {
		if (Name == BRANCH_NONAME)return;
		animClock++;
		DrawFormatString(getX() + 5, getY() - 17, GetColor(100, 255, 100), "%s", animClock % 120 < 50 ? Name.c_str() : NameReading.c_str());
	}
}

