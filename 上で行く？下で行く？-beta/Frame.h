#pragma once
#include"MyaObject.h"
#include"MapData.h"
#include"Car.h"
#include"DrivePlan.h"
#include"IntroLeader.h"
#include"SceneChangable.h"
#include"ClearLeader.h"
#include"DrivingLeader.h"
#include"OverLeader.h"
#include<string>
using namespace std;

#define IntroMessageMax 26

class Leadable;

class Frame :public SceneChangable, MyaO
{
private:
	Leadable * myLeader=nullptr;
	FrameScene nextQue;

	//•”‰º
	MapData * MyMap = nullptr;
	Car *MyCar = nullptr;
	int BgCol;

	//‰¼‘z‰æ–ÊŒn
	int MapScreen;

	DrivePlan *MyDrivePlan;
public:
	void changeScene(FrameScene next)override;
	void init();
	void update() {};
	void draw() {};
	void doMainLoop();

	void finalize();
};
