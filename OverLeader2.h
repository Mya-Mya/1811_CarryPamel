#pragma once
#include"Leadable.h"
#include"SceneChangable.h"
#include"MessageCard.h"
#include"Config.h"
#include"Toggle.h"
#include"ActionListener.h"
class OverLeader2:public Leadable, ActionListener
{
private:
	MessageCard * msc;
	Toggle *prevPage;
	Toggle *nextPage;
	Toggle *retry;
	int MES_FIN;
public:
	OverLeader2(MapData*map,Car*car,DrivePlan*driveplan,SceneChangable*changer);
	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;

	void actionPerformed(EventObj*e)override;
};