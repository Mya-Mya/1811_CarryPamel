#pragma once
#include"SceneLeadable.h"
#include"Config.h"
class DrivingLeader : public SceneLeadable {
public:
	DrivingLeader(MapData*map, Car*car, DrivePlan*driveplan, SceneChangable *changer) :SceneLeadable(map, car,driveplan, changer) {};

	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;
};