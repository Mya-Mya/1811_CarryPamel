#include "OverLeader.h"
#include"DxLib.h"


OverLeader::OverLeader(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
	:Leadable(map, car, driveplan, changer)
{
	ol2 = new OverLeader2(map, car, driveplan, changer);
	iHandle = LoadGraph("GameOverImage.png", TRUE);
}

void OverLeader::update()
{
	if (animDone) {
		ol2->update();
		return;
	}
	t++;
	if (t < t0)a = 0;
	if (t0 < t && t < t1) a = 255/(t1-t0)*(t-t0);
	if (t1 <= t && t <= t2) a = 255;
	if (t2 < t) a = 255-(255/(t3-t2))*(t-t2);
	if (t > t3)animDone = true;
}

void OverLeader::draw()
{
	if (animDone) {
		ol2->draw();
		return;
	}
	DrawBox(0, 0, WND_X, WND_Y, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, a);
	DrawRotaGraph(WND_X*0.5, WND_Y*0.5, 1, 0, iHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}
void OverLeader::drawAsMap() {
	if (animDone)ol2->drawAsMap();
}

double OverLeader::getMapExr()
{
	return animDone ? ol2->getMapExr() : 1;
}

int OverLeader::getMapX()
{
	return animDone ? ol2->getMapX() : 0;
}

int OverLeader::getMapY()
{
	return animDone ? ol2->getMapX() : 0;
}
