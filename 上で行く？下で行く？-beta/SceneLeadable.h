#pragma once
#include"MyaObject.h"
#include"MapDrawable.h"
#include"MapData.h"
#include"SceneChangable.h"
#include"Car.h"
#pragma warning(disable:4244)

class SceneLeadable :public MyaO {
protected:
	MapData * remoteMap;
	Car *remoteCar;
	SceneChangable *changer;
	DrivePlan*drivePlan;
public:
	SceneLeadable(MapData*map, Car*car, DrivePlan*driveplan, SceneChangable*changer)
	:remoteMap(map), remoteCar(car),changer(changer),drivePlan(driveplan) {};

	virtual void init()override = 0;
	virtual void update()override = 0;
	virtual void draw()override = 0;
	virtual void drawAsMap() = 0;
	virtual double getMapExr() = 0;
	virtual int getMapX() = 0;
	virtual int getMapY() = 0;
};