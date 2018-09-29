#pragma once
#include"SceneLeadable.h"
#include"MessageCard.h"

class IntroLeader :public SceneLeadable
{
private:
	MessageCard * message;
	int MES_SHOWSTART;
	int MES_SHOWGOAL;
public:
	IntroLeader(MapData *map, Car *car,DrivePlan*driveplan,SceneChangable *changer);
	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;
};

