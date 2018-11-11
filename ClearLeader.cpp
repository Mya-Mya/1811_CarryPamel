#include "ClearLeader.h"
#include"DxLib.h"

ClearLeader::ClearLeader(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
	:Leadable(map, car, driveplan, changer)
{
	int ToggleW = 200, ToggleH = 100, ToggleY = WND_Y - ToggleH,
		ToggleXStarting = WND_X - 2 * ToggleW,
		ToggleFontSize = 40;
	prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "���O", ToggleFontSize, KEY_INPUT_LEFT);
	prevPage->addActionListener(this);
	nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "����", ToggleFontSize, KEY_INPUT_RIGHT);
	nextPage->addActionListener(this);

	msc = new MessageCard(20, WND_Y - 140, 30, GetColor(240, 240, 240), GetColor(40, 40, 40));
	
	msc->addPage("�悭����������F��");
	msc->addPage("�����Ƀp�����͖ړI�n�ւ��ǂ蒅�����Ƃ��ł���");
	msc->addPage("����������ăQ�[���͂����܂���");
	msc->addPage("�N�����ꂩ��C��t���ċA���");
	MES_FIN = msc->addPage("����ł͂悫�����Ղ��I���悤�Ȃ�I(�I)");
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
