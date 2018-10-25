#include "Frame.h"
#include"DxLib.h"
#include"Config.h"
#include"Singleton.h"


void Frame::changeScene(FrameScene next)
{
	nextQue = next;
}

void Frame::init()
{
	SetDoubleStartValidFlag(TRUE);
	SetWindowText("パメルを運べ");
SetGraphMode(WND_X, WND_Y, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	MyMap = new MapData();
	MyMap->init();
	MyCar = new Car();
	MyCar->init();
	MyDrivePlan= MyMap->getDrivePlan();
	MyCar->setPosition(MyDrivePlan->start);

	BgCol = GetColor(250, 250, 250);
	MapScreen = MakeScreen(MAP_SCREEN_W, MAP_SCREEN_H, TRUE);

	changeScene(Intro);
}

void Frame::doMainLoop()
{
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		DrawBox(0, 0, WND_X, WND_Y, BgCol, TRUE);
		Keyboard::Instance()->Update();

		if (nextQue != None) {
			if (myLeader != nullptr)delete myLeader;
			switch (nextQue)
			{
			case Intro:
				myLeader = (Leadable*)new IntroLeader(MyMap, MyCar, MyDrivePlan, this);
				break;
			case Driving:
				myLeader = (Leadable*)new DrivingLeader(MyMap, MyCar, MyDrivePlan, this);
				break;
			case Clear:
				myLeader = (Leadable*)new ClearLeader(MyMap, MyCar, MyDrivePlan, this);
				break;
			case Over:
				myLeader = (Leadable*)new OverLeader(MyMap, MyCar, MyDrivePlan, this);
			}
			nextQue = None;
		}
		
		myLeader->update();

		SetDrawScreen(MapScreen);//地図スクリーン
		SetFontSize(25 / myLeader->getMapExr());
		ClearDrawScreen();
		myLeader->drawAsMap();
		SetDrawScreen(DX_SCREEN_BACK);
		DrawRotaGraph(
			myLeader->getMapX(), myLeader->getMapY(), myLeader->getMapExr(), 0,
			MapScreen, TRUE
		);

		myLeader->draw();
	}
}

void Frame::finalize()
{
	DxLib_End();
}