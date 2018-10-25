#pragma once
#include"Leadable.h"
#include"Config.h"
#include"MessageCard.h"
#include<list>
using namespace std;

class Bar;
class DrivingLeader : public Leadable {
private:
	MessageCard * msc;
	int MES_TODEP;
	int MES_ONTOP1;
	int MES_SPACE;

	int MES_BLIND;
	int MES_TOOLONGSTOP;

	int MES_LOW;
	int MES_HIGH;

	int MES_NONE;

	int MES_TEMPR09;
	int MES_TEMPR03;
	int MES_TEMPR02;
	int MES_TEMPR01;

	int MES_GOSSIP[7];

	Bar *ptemperBar;
	double Ptemper=0.7;

	int gosippingT = 0;

	int drivingT = 0;//�p����#1 �o������̌o�ߎ��Ԕ���
	int stoppingT = 0;//�p����#2 �~�܂肷��
	int wrongBlindSpotFlag = 0;//�p����#3 �Ⴄ�s���~�܂�
	list<int> speedLog; int displace; int lowLasting;int highLasting;//�p����#4 �̂�̂�^�]�͌��ł���

public:
	DrivingLeader(MapData*map, Car*car, DrivePlan*driveplan, SceneChangable *changer) ;

	void init()override {};
	void update()override;
	void draw()override;
	void drawAsMap()override;
	double getMapExr()override;
	int getMapX()override;
	int getMapY()override;
};

class Bar:public MyaO {
private:
	int x1, y;
	double exr;
	double current;
public:
	Bar(int x1,int y, double exr) { this->x1 = x1,this->y=y, this->exr = exr; };
	void init()override {};
	void setCurrent(double current);
	void update()override {};

	void draw()override;
};