#include "IntroLeader.h"
#include"DxLib.h"
#include"Singleton.h"
#include"WhatToDraw.h"
#include"Config.h"

IntroLeader::IntroLeader(MapData * map, Car * car,DrivePlan *driveplan,SceneChangable *changer)
	:SceneLeadable(map,car,driveplan,changer)
{
	message = new MessageCard(50, 50, 25, GetColor(240, 240, 240), GetColor(40, 40, 40));
	message->addPage("どうも。このゲームの進行を担当する");
	message->addPage("あなたの友人かつ隣人にあたる人物、パメルと申す");
	MES_SHOWSTART=message->addPage("私達は今この場所にあるショッピングモールで");
	message->addPage("「ウィンドウショッピング」たるものを嗜(たしな)んできた");
	message->addPage("今はショッピングモールを出て、パメルとあなたは駐車場にいる");
	message->addPage("私、パメルはあなたの車に乗ってこのショッピングモールまで来た");
	message->addPage("あなたは帰るのみかもしれないが、私は違う");
	MES_SHOWGOAL=message->addPage("私、パメルはこれからこの街に少々用事がある");
	message->addPage("だが今この場にはあなたの車しかない");
	message->addPage("お手数なのだが、パメルをこの場所まで乗せてくれないか");
	message->addPage("申し訳ないのだが、時間が無いのだ");
	message->addPage("え？早く「ｳｨﾝﾄﾞｳｼｮｯﾋﾟﾝｸﾞ」を切り上げれば良かっただと！？");
	message->addPage("それは十分承知だが、パメルにはそのようなことはできぬ");
	message->addPage("お主、いかに「ｳｨﾝﾄﾞｳｼｮｯﾋﾟﾝｸﾞ」が重要な文化であるか、知らないのか");
	message->addPage("（※本アプリケーション開発者(5年宮岡)もよく知りません）");
	message->addPage("まあよい。取り敢えず送迎の件、あなたに頼む。ありがとう");
	message->addPage("【読んで】今からルールと仕組みを説明する。よく読むように");
	message->addPage("(1)なるべく早く到着するように。時間が経ちすぎると・・・");
	message->addPage("(2)車は交差点で止まっている間に、右か左かまっすぐかを「矢印キー」で指定できる");
	message->addPage("(3)いざという時は後退もできる。これは「エンターキー」で指定できる");
	message->addPage("(4)交通渋滞というものが存在し、混み具合により車の速度が変わる");
	message->addPage("ただし、交通渋滞はいつも見られるわけではない");
	message->addPage("走行中は、あなたは車を運転するのだから、前を見ていなければならない");
	message->addPage("(5)止まっている間だけ、「スペースキー」を押せば交通渋滞がみられる");
	message->addPage("(6)ゲーム中は目的地であるというマークは表示されない");
	message->addPage("以上だ。時間もないので今すぐ出発してくれ");
}

void IntroLeader::update()
{
	if (Keyboard::Instance()->Get(KEY_INPUT_RIGHT) == 1) {
		message->nextPage();
		if (message->isEnd())changer->changeScene(Driving);
	}
}

void IntroLeader::draw()
{
	message->draw();
}

void IntroLeader::drawAsMap()
{
	remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	remoteMap->drawOnMap();

	if (message->nowPage() >= MES_SHOWSTART)
		DrawCircle(drivePlan->start->getX(), drivePlan->start->getY(), 200, GetColor(255, 50, 80), FALSE, 7);
	if (message->nowPage() >= MES_SHOWGOAL)
		DrawCircle(drivePlan->goal->getX(), drivePlan->goal->getY(), 200, GetColor(70, 40, 255), FALSE, 8);

	remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	remoteMap->drawOnMap();
}

double IntroLeader::getMapExr()
{
	return 0.25;
}

int IntroLeader::getMapX()
{
	return WND_X*0.5;
}

int IntroLeader::getMapY()
{
	return WND_Y*0.5;
}
