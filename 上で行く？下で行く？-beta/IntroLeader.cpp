#include "IntroLeader.h"
#include"DxLib.h"
#include"Singleton.h"
#include"WhatToDraw.h"
#include"Config.h"

IntroLeader::IntroLeader(MapData * map, Car * car)
	:SceneLeadable(map,car)
{
	message = new MessageCard(50, 50);
	message->add("どうも。このゲームの進行を担当する");
	message->add("あなたの友人かつ隣人にあたる人物、パメルと申す");
	/*Index=2*/message->add("私達は今この場所にあるショッピングモールで");
	message->add("「ウィンドウショッピング」たるものを嗜(たしな)んできた");
	message->add("今はショッピングモールを出て、パメルとあなたは駐車場にいる");
	message->add("私、パメルはあなたの車に乗ってこのショッピングモールまで来た");
	message->add("あなたは帰るのみかもしれないが、私は違う");
	/*Index=7*/message->add("私、パメルはこれからこの街に少々用事がある");
	message->add("だが今この場にはあなたの車しかない");
	message->add("お手数なのだが、パメルをこの場所まで乗せてくれないか");
	message->add("申し訳ないのだが、時間が無いのだ");
	message->add("え？早く「ｳｨﾝﾄﾞｳｼｮｯﾋﾟﾝｸﾞ」を切り上げれば良かっただと！？");
	message->add("それは十分承知だが、パメルにはそのようなことはできぬ");
	message->add("お主、いかに「ｳｨﾝﾄﾞｳｼｮｯﾋﾟﾝｸﾞ」が重要な文化であるか、知らないのか");
	message->add("（※本アプリケーション開発者(5年宮岡)もよく知りません）");
	message->add("まあよい。取り敢えず送迎の件、あなたに頼む。ありがとう");
	message->add("【読んで】今からルールと仕組みを説明する。よく読むように");
	message->add("(1)なるべく早く到着するように。時間が経ちすぎると・・・");
	message->add("(2)車は交差点で止まっている間に、右か左かまっすぐかを「矢印キー」で指定できる");
	message->add("(3)いざという時は後退もできる。これは「エンターキー」で指定できる");
	message->add("(4)交通渋滞というものが存在し、混み具合により車の速度が変わる");
	message->add("ただし、交通渋滞はいつも見られるわけではない");
	message->add("走行中は、あなたは車を運転するのだから、前を見ていなければならない");
	message->add("(5)止まっている間だけ、「スペースキー」を押せば交通渋滞がみられる");
	message->add("(6)ゲーム中は目的地であるというマークは表示されない");
	message->add("以上だ。時間もないので今すぐ出発してくれ indexOf 25");
}

void IntroLeader::update()
{
	if (Keyboard::Instance()->Get(KEY_INPUT_RIGHT) == 1) {
		message->nextPage();
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
	remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	remoteMap->drawOnMap();
	//車は描画しないよ
}

double IntroLeader::getMapExr()
{
	return 0.25;
}

int IntroLeader::getMapX()
{
	return WINDOW_X*0.5;
}

int IntroLeader::getMapY()
{
	return WINDOW_Y*0.5;
}
