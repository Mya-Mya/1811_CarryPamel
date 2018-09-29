#pragma once
#include"MyaObject.h"
#include"MapData.h"
#include"Car.h"
#include"DrivePlan.h"
#include"ImageDrawer.h"
#include"IntroLeader.h"
#include"SceneChangable.h"
#include"DrivingLeader.h"
#include<string>
using namespace std;

#define IntroMessageMax 26

class SceneLeadable;

class Frame :public SceneChangable, MyaO
{
private:
	SceneLeadable * myLeader=nullptr;

	//•”‰º
	MapData * MyMap = nullptr;
	Car *MyCar = nullptr;
	int BgCol;

	//‰¼‘z‰æ–ÊŒn
	int MapScreen;

	DrivePlan *MyDrivePlan;
public:
	void changeScene(FrameScene next)override;
	//static int Width;
	//static int Height;
	void init();
	void update() {};
	void draw() {};
	void doMainLoop();

	//void doIntro();”pŽ~
	//void doDriving();
	//void doClear();
	void finalize();
};
