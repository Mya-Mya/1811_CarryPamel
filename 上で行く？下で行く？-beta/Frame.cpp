#include "Frame.h"
#include"DxLib.h"
#include"Config.h"
#include"Singleton.h"


void Frame::changeScene(FrameScene next)
{
	if(myLeader!=nullptr)delete myLeader;
	switch (next)
	{
	case Intro:
		myLeader = (SceneLeadable*)new IntroLeader(MyMap, MyCar,MyDrivePlan,this);
		break;
	case Driving:
		myLeader = (SceneLeadable*)new DrivingLeader(MyMap, MyCar, MyDrivePlan,this);
		break;
	case Clear:
		break;
	}
}

void Frame::init()
{
	SetDoubleStartValidFlag(TRUE);
	SetWindowText("上で行く？下で行く？beta 20180929");
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
/*
void Frame::doClear() 
{
	SetDrawScreen(MapScreen);
	ClearDrawScreen();
	
	MyMap->drawOnMap();

	SetDrawScreen(DX_SCREEN_BACK);
	DrawRotaGraph(Frame::Width *0.5, Frame::Height*0.5, MapScreenExr, 0, MapScreen, TRUE);

	Message = "お前よくやったぞ";
	drawMessage();
}
*/
void Frame::finalize()
{
	DxLib_End();
}