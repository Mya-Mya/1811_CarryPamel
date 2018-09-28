#pragma once
#include"MyaObject.h"

#include "iBranch.h"
#include"MapDrawable.h"
#include<string>
using namespace std;
#define BRANCH_NONAME "noname_branch"


class Branch :public iBranch,MapDrawable 
	,MyaO
{
private:
	int x;
	int y;
	Point* point[4];
	string Name=BRANCH_NONAME, NameReading=BRANCH_NONAME;

	MapWhatToDraw WhatToDraw;
	int animClock = 0;
public:
	Branch(int x,int y);
	void init() {};
	Branch* makePoint(int branchNum);
	Point* getPoint(int branchNum);

	void update() {};

	void setWhatToDraw(MapWhatToDraw WhatToDraw);
	void draw() {};
	void rgstName(string name, string namereading);

	void setScreenTS(bool IfScreenTS);
	
	/*from iBranch*/
	bool canTurn(Point*nowpoint, TurnDirection td) override;
	Point* turn(Point*nowpoint, TurnDirection td) override;
	int getX() override;
	int getY() override;
	string getName() override;

	/*from MapDrawable*/
	void drawOnMap()override;
};

/*
é}î‘çÜÇÕ
âEâÒÇËÇÃï˚å¸Ç…0,1,2,3
*/