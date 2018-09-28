#pragma once
#include"MyaObject.h"
#include"DrivePlan.h"
#include"Branch.h"
#include"TrafficState.h"
#include<list>
#include<vector>
#include"MapDrawable.h"

using namespace std;
#define MAP_SCREEN_W 3000
#define MAP_SCREEN_H 2800

class MapData:public  MapDrawable 
	, MyaO
{
private:
	list<Branch*> mapdata;
	vector<DrivePlan*> driveplans;
	void linkEachPoint(Point*, Point*, TrafficState);

	TrafficState randomTS();

	MapWhatToDraw WhatToDraw;
public:

	void init();

	DrivePlan* getDrivePlan();
	void draw() {};


	void update() {};
	void setScreenTS(bool IfScreenTS);
	void setWhatToDraw(MapWhatToDraw WhatToDraw);
	/*from MapDrawable*/
	void drawOnMap()override;
};

