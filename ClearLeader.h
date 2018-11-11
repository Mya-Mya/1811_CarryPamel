#pragma once
#include "Leadable.h"
#include"SceneChangable.h"
#include"MessageCard.h"
#include"Config.h"
#include"Toggle.h"
#include"ActionListener.h"

class ClearLeader :
	public Leadable, ActionListener
{
private:
	MessageCard * msc;
	Toggle *prevPage;
	Toggle *nextPage;
	int MES_FIN;
public:
	ClearLeader(MapData*map,Car*car,DrivePlan*driveplan,SceneChangable*changer);

	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;

	void actionPerformed(EventObj *e)override;
};

