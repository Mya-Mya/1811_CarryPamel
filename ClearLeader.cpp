#include "ClearLeader.h"
#include"DxLib.h"

ClearLeader::ClearLeader(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
	:Leadable(map, car, driveplan, changer)
{
	int ToggleW = 200, ToggleH = 100, ToggleY = WND_Y - ToggleH,
		ToggleXStarting = WND_X - 2 * ToggleW,
		ToggleFontSize = 40;
	prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "←前", ToggleFontSize, KEY_INPUT_LEFT);
	prevPage->addActionListener(this);
	nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "次→", ToggleFontSize, KEY_INPUT_RIGHT);
	nextPage->addActionListener(this);

	msc = new MessageCard(20, WND_Y - 140, 30, GetColor(240, 240, 240), GetColor(40, 40, 40));
	
	msc->addPage("よくやったぞぉ友よ");
	msc->addPage("無事にパメルは目的地へたどり着くことができた");
	msc->addPage("これをもってゲームはおしまいだ");
	msc->addPage("君もこれから気を付けて帰れよ");
	MES_FIN = msc->addPage("それではよき文化祭を！さようなら！(終)");
}

void ClearLeader::update()
{
	nextPage->setAvailable(
		(msc->nowPage() == MES_FIN) ? false : true
	);
	nextPage->update();
	prevPage->update();
}

void ClearLeader::draw()
{
	msc->draw();
	nextPage->draw();
	prevPage->draw();
}

void ClearLeader::drawAsMap()
{
	remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	remoteMap->drawOnMap();
	remoteCar->drawOnMap();
	remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	remoteMap->drawOnMap();
}

double ClearLeader::getMapExr()
{
	return 0.2;
}

int ClearLeader::getMapX()
{
	return WND_X*0.5;
}

int ClearLeader::getMapY()
{
	return WND_Y*0.5;
}

void ClearLeader::actionPerformed(EventObj * e)
{
	if (e == nextPage) { 
		msc->nextPage(); 
		if (msc->isEnd())msc->jumpTo(MES_FIN);
	}
	if (e == prevPage)msc->prevPage();
}
