#pragma once
#include"Leadable.h"
#include"SceneChangable.h"
#include"MessageCard.h"
#include"Config.h"
#include"Toggle.h"
#include"ActionListener.h"
#include"OverLeader2.h"

class OverLeader :public Leadable {
private:
	Leadable * ol2;
	bool animDone = false;
	int iHandle;
	/*
	“§‰ß—¦a
	= 0 for t<t0
	= 255/(t1-t0)(t-t0) for t0<t<t1
	= 255 for t1<t<t2
	= 255 - (255/(t3-t2))(t-t2) (t2<t)
	*/
	double a=0;
	double t = 0;
	const double t0=55,t1=80,t2=180,t3=300;
public:
	OverLeader(MapData*map, Car*car, DrivePlan*driveplan, SceneChangable*changer);
	void init()override {};
	void update()override;
	void draw()override ;
	void drawAsMap()override ;
	double getMapExr()override ;
	int getMapX()override ;
	int getMapY()override;
};

