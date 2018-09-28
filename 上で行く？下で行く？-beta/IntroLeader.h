#pragma once
#include"SceneLeadable.h"
#include"MessageCard.h"

class IntroLeader :public SceneLeadable
{
private:
	MessageCard * message;
public:
	IntroLeader(MapData *map, Car *car);
	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;
};

