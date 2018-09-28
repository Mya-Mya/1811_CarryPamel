#pragma once
#include"MyaObject.h"
#include"iBranch.h"
#include"TrafficState.h"
#include"MapDrawable.h"
#include<string>
using namespace std;

class Point :public MapDrawable, 
	MyaO
{
private:
	iBranch * MyBranch;
	Point *MyLink;
	TrafficState MyTS=TrafficState_None;
	int LineColor;

	bool IFScreenTS = false;
public:
	void rgstLink(Point*link,TrafficState ts);
	void rgstrIBranch(iBranch *you);
	void init();
	void update() {};
	void draw() {};
	void setScreenTS(bool IFScreenTS);

	iBranch *getBranch();
	int getX();
	int getY();
	
	bool canTurn(TurnDirection);
	Point *turn(TurnDirection);

	Point* getLink();
	TrafficState getTS();

	/*from MapDrawable*/
	void drawOnMap()override;
};
