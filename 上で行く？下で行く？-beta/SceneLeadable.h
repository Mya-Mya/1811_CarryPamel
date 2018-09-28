#pragma once
#include"MyaObject.h"
#include"MapDrawable.h"
#include"MapData.h"
#include"Car.h"

class SceneLeadable :public MyaO {
protected:
	MapData * remoteMap;
	Car *remoteCar;
public:
	SceneLeadable(MapData*map, Car*car)
	:remoteMap(map), remoteCar(car) {};

	virtual void init()override = 0;
	virtual void update()override = 0;
	virtual void draw()override = 0;
	virtual void drawAsMap() = 0;
	virtual double getMapExr() = 0;
	virtual int getMapX() = 0;
	virtual int getMapY() = 0;
};