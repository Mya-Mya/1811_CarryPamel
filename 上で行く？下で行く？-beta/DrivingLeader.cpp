
#include "DrivingLeader.h"
#include"Singleton.h"
#include"DxLib.h"

void DrivingLeader::update()
{
	remoteCar->update();
	remoteMap->setScreenTS(false);
	if (!remoteCar->isRunning())if (CheckHitKey(KEY_INPUT_SPACE)!=0)remoteMap->setScreenTS(true);
}

void DrivingLeader::draw()
{
	remoteCar->draw();
}

void DrivingLeader::drawAsMap()
{
	remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	remoteMap->drawOnMap();
	remoteCar->drawOnMap();
	remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	remoteMap->drawOnMap();
}

double DrivingLeader::getMapExr()
{
	return 1.0;
}

int DrivingLeader::getMapX()
{
	return WND_X*0.5+MAP_SCREEN_W*0.5*getMapExr()-remoteCar->getX()*getMapExr();
}

int DrivingLeader::getMapY()
{
	return WND_Y*0.5 + MAP_SCREEN_H*0.5*getMapExr() - remoteCar->getY()*getMapExr();
}
