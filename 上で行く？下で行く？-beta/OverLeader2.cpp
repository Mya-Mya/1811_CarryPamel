#include "OverLeader2.h"
#include"DxLib.h"

OverLeader2::OverLeader2(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
:Leadable(map,car,driveplan,changer)
{
int ToggleW = 200, ToggleH = 100, ToggleY = WND_Y - ToggleH,
ToggleXStarting = WND_X - 2 * ToggleW,
ToggleFontSize = 40;
prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "←前", ToggleFontSize, KEY_INPUT_LEFT);
prevPage->addActionListener(this);
nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "次→", ToggleFontSize, KEY_INPUT_RIGHT);
nextPage->addActionListener(this);

msc = new MessageCard(20, WND_Y - 140, 30, GetColor(240, 240, 240), GetColor(209, 86, 95));

msc->addPage("あなたは私の機嫌を０にした");
msc->addPage("・・・・・・");
msc->addPage("今回はゲームオーバーとする");
msc->addPage("あなたは快適な運転を\nしなければならないと何度言ったことか");
msc->addPage("(1回も言っていない)");
msc->addPage("でも、このゲームをもう一回やるにしても\nこれで終わりにするも");
msc->addPage("今回のゲームで私の機嫌が\nどんな風に変化するか分かっただろう");
msc->addPage("私のこの機嫌調整プログラムは\n製作者がかなり頑張ったようだからな");
MES_FIN=msc->addPage("あなたにこのゲームを楽しんでもらってよかった\nこの先も気を付けて(終了)");
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