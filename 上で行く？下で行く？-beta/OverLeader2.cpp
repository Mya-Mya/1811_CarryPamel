#include "OverLeader2.h"
#include"DxLib.h"

OverLeader2::OverLeader2(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
:Leadable(map,car,driveplan,changer)
{
int ToggleW = 200, ToggleH = 100, ToggleY = WND_Y - ToggleH,
ToggleXStarting = WND_X - 2 * ToggleW,
ToggleFontSize = 40;
prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "���O", ToggleFontSize, KEY_INPUT_LEFT);
prevPage->addActionListener(this);
nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "����", ToggleFontSize, KEY_INPUT_RIGHT);
nextPage->addActionListener(this);

msc = new MessageCard(20, WND_Y - 140, 30, GetColor(240, 240, 240), GetColor(209, 86, 95));

msc->addPage("���Ȃ��͎��̋@�����O�ɂ���");
msc->addPage("�E�E�E�E�E�E");
msc->addPage("����̓Q�[���I�[�o�[�Ƃ���");
msc->addPage("���Ȃ��͉��K�ȉ^�]��\n���Ȃ���΂Ȃ�Ȃ��Ɖ��x���������Ƃ�");
msc->addPage("(1��������Ă��Ȃ�)");
msc->addPage("�ł��A���̃Q�[�������������ɂ��Ă�\n����ŏI���ɂ����");
msc->addPage("����̃Q�[���Ŏ��̋@����\n�ǂ�ȕ��ɕω����邩�����������낤");
msc->addPage("���̂��̋@�������v���O������\n����҂����Ȃ�撣�����悤�������");
MES_FIN=msc->addPage("���Ȃ��ɂ��̃Q�[�����y����ł�����Ă悩����\n���̐���C��t����(�I��)");
}

void OverLeader2::update()
{
nextPage->setAvailable(
(msc->nowPage() == MES_FIN) ? false : true
);
nextPage->update();
prevPage->update();
}

void OverLeader2::draw()
{
msc->draw();
nextPage->draw();
prevPage->draw();
}

void OverLeader2::drawAsMap()
{
remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
remoteMap->drawOnMap();
remoteCar->drawOnMap();
remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
remoteMap->drawOnMap();
}

double OverLeader2::getMapExr()
{
return 0.3;
}

int OverLeader2::getMapX()
{
return WND_X*0.5;
}

int OverLeader2::getMapY()
{
return WND_Y*0.5;
}

void OverLeader2::actionPerformed(EventObj * e)
{
if (e == nextPage) {
msc->nextPage();
if (msc->isEnd())msc->jumpTo(MES_FIN);
}
if (e == prevPage)msc->prevPage();
}