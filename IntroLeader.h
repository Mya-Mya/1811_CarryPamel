#pragma once
#include"Leadable.h"
#include"MessageCard.h"
#include"Toggle.h"
#include"ActionListener.h"
class IntroLeader :public Leadable, ActionListener
{
private:
	MessageCard * msc;
	Toggle *nextPage, *prevPage;

	int MES_SHOWSTART;
	int MES_SHOWGOAL;
	int MES_PUSHTODEP;
public:
	IntroLeader(MapData *map, Car *car,DrivePlan*driveplan,SceneChangable *changer);
	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;

	void actionPerformed(EventObj*e)override;
};

