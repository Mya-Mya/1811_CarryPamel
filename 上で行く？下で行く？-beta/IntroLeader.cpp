#include "IntroLeader.h"
#include"DxLib.h"
#include"Singleton.h"
#include"WhatToDraw.h"
#include"Config.h"

IntroLeader::IntroLeader(MapData * map, Car * car,DrivePlan *driveplan,SceneChangable *changer)
	:Leadable(map,car,driveplan,changer)
{
	int ToggleW = 200, ToggleH = 100, ToggleY = WND_Y - ToggleH,
		ToggleXStarting = WND_X-2*ToggleW,
		ToggleFontSize = 40;
	prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "←前", ToggleFontSize, KEY_INPUT_LEFT);
	prevPage->addActionListener(this);
	nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "次→", ToggleFontSize, KEY_INPUT_RIGHT);
	nextPage->addActionListener(this);

	msc = new MessageCard(20, WND_Y-140, 30, GetColor(240, 240, 240), GetColor(40, 40, 40));
	msc->addPage("私は、このゲームの進行を担当する");
	msc->addPage("あなたの友人、パメルと申す");
	MES_SHOWSTART=msc->addPage("私たちは、今この赤いまるの所で");
	msc->addPage("ショッピングモールでのお買い物を楽しんでいた\n超楽しかったね！");
	msc->addPage("今は帰るところ。私たちは駐車場にいる");
	msc->addPage("パメルは、あなたの車に乗ってここへ来た");
	msc->addPage("あなたは帰るのみかもしれないが、私は違う");
	MES_SHOWGOAL=msc->addPage("これから、パメルはこの青い丸の所に用事がある");
	msc->addPage("行かなきゃいけない\nでも、ここにはあなたの車しかない");
	msc->addPage("お手数なのだが、私をここまで送ってくれないか");
	msc->addPage("ありがとう。君は優しいね。よろしく頼むよ");
	msc->addPage("【よく読んで】それじゃあ、ルールを説明する");
	msc->addPage("(1)私を怒らせてはいけない。\n画面上の方に私の機嫌が表示される");
	msc->addPage("機嫌がゼロになったら私は怒る。\nそしたらゲームオーバーだ！");
	msc->addPage("私の機嫌をとる方法は4つある");
	msc->addPage("ひとつは、早く到着すること\nそしてふたつめは・・・");
	msc->addPage("教えませーーん\n教えちゃうとこのゲームが面白くないからね");
	msc->addPage("運転してるうちに分かるよきっと\n私をよく観察してよく考えることね！");
	msc->addPage("(2)交差点で止まっている間に、\n「矢印キー」で進む方向をえらべる。");
	msc->addPage("(3)いきどまりに来たら、「エンターキー」で戻れる。");
	msc->addPage("(4)渋滞があり、混み具合によって車の速さが変わる");
	msc->addPage("(5)「スペースキー」をおせば渋滞がみられる。\nただし止まっている時だけ");
	msc->addPage("道路交通法第71条第5号の5 にもあるけど\n走りながらは渋滞見るのは危ない。運転集中だぞっ！");
	msc->addPage("(6)運転中は赤い丸や青い丸は表示されない\n目的地をちゃんと覚えておくこと");
	msc->addPage("ルールは分かった？最後に、地図全体を確認してねだよ");
	msc->addPage("「→」で次へ");
	MES_PUSHTODEP=msc->addPage("それでは、出発進行！！\n赤が出発、青が目的地！");

	//message->jumpTo(MES_PUSHTODEP);
}

void IntroLeader::update()
{
	if (msc->isEnd())changer->changeScene(Driving);
	nextPage->update();
	prevPage->update();
	if (msc->nowPage() == MES_PUSHTODEP)nextPage->setText("出発→");
}

void IntroLeader::draw()
{
	msc->draw();
	nextPage->draw();
	prevPage->draw();
}

void IntroLeader::drawAsMap()
{
	remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	remoteMap->drawOnMap();

	if (msc->nowPage() >= MES_SHOWSTART)
		DrawCircle(drivePlan->start->getX(), drivePlan->start->getY(), 200, GetColor(255, 50, 80), FALSE, 7);
	if (msc->nowPage() >= MES_SHOWGOAL)
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

void IntroLeader::actionPerformed(EventObj * e)
{
	if(e==nextPage)msc->nextPage();
	if (e == prevPage) { msc->prevPage(); nextPage->setText("次→"); }
}
