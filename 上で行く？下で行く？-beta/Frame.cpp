#include "Frame.h"
#include"DxLib.h"
#include"Singleton.h"

int Frame::Width = 1280;
int Frame::Height = 720;

void Frame::changeScene(sPamel next)
{
	switch (next)
	{
	case Intro:
		myScene = (SceneLeadable*)new IntroLeader(MyMap, MyCar);
		break;
	case Driving:
		break;
	case Clear:
		break;
	default:
		break;
	}
}

void Frame::init()
{
SetGraphMode(Frame::Width, Frame::Height, 32);
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
		DrawBox(0, 0, Frame::Width, Frame::Height, BgCol, TRUE);
		Keyboard::Instance()->Update();
		
		myScene->update();

		SetDrawScreen(MapScreen);
		SetFontSize(20 / myScene->getMapExr());
		ClearDrawScreen();
		myScene->drawAsMap();
		SetDrawScreen(DX_SCREEN_BACK);
		DrawRotaGraph(
			myScene->getMapX(), myScene->getMapY(), myScene->getMapExr(), 0,
			MapScreen, TRUE
		);

		myScene->draw();
		/*
		SetFontSize(20 / MapScreenExr);
		switch (now)
		{
		case Intro:
			MapScreenExr = 0.25;
			doIntro();
			break;
		case Driving:
			MapScreenExr = 1.00;
			doDriving();
			break;
		case Clear:
			MapScreenExr = 0.25;
			doClear();
			break;
		}
		*/
	}
}
/*
void Frame::doDriving()
{
	MyMap->setScreenTS(false);
	if (!MyCar->isRunning()) {
		if (CheckHitKey(KEY_INPUT_SPACE)) MyMap->setScreenTS(true);
	}

	MyCar->update();
	if (MyCar->getCurrentBranch() == MyDrivePlan->goal)now = Clear;

	SetDrawScreen(MapScreen);
	ClearDrawScreen();
	MyMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	MyMap->drawOnMap();
	MyCar->drawOnMap();
	MyMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	MyMap->drawOnMap();
	SetDrawScreen(DX_SCREEN_BACK);
	//ŽÔ‚ª‰æ–Ê’†‰›‚É—ˆ‚é‚æ‚¤‚É‰¼‘z‰æ–Ê‚ð•`‰æ
	DrawRotaGraph(
		Frame::Width *0.5 + MAP_SCREEN_W * 0.5*MapScreenExr - MyCar->getX()*MapScreenExr,
		Frame::Height*0.5 + MAP_SCREEN_H * 0.5*MapScreenExr - MyCar->getY()*MapScreenExr,
		MapScreenExr, 0, MapScreen, TRUE);
	MyCar->draw();
}
*/
/*
void Frame::doClear() 
{
	SetDrawScreen(MapScreen);
	ClearDrawScreen();
	
	MyMap->drawOnMap();

	SetDrawScreen(DX_SCREEN_BACK);
	DrawRotaGraph(Frame::Width *0.5, Frame::Height*0.5, MapScreenExr, 0, MapScreen, TRUE);

	Message = "‚¨‘O‚æ‚­‚â‚Á‚½‚¼";
	drawMessage();
}
*/
void Frame::finalize()
{
	DxLib_End();
}


