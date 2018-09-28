#pragma once
#include"MyaObject.h"
#include"MapData.h"
#include"Car.h"
#include"DrivePlan.h"
#include"ImageDrawer.h"
#include"IntroLeader.h"
#include<string>
using namespace std;

#define IntroMessageMax 26

enum sPamel {
	Intro,
	Driving,
	Clear,
};

class SceneLeadable;

class Frame :public MyaO
{
private:
	SceneLeadable * myScene;

	//部下
	MapData * MyMap = nullptr;
	Car *MyCar = nullptr;
	int BgCol;

	//仮想画面系
	int MapScreen;

	DrivePlan *MyDrivePlan;
public:
	void changeScene(sPamel next);//インターフェース化するね
	static int Width;
	static int Height;
	void init();
	void update() {};
	void draw() {};
	void doMainLoop();

	//void doIntro();廃止
	//void doDriving();
	//void doClear();
	void finalize();
};
