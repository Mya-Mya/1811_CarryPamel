
#include "DrivingLeader.h"
#include"Singleton.h"
#include"DxLib.h"
#include<numeric>

DrivingLeader::DrivingLeader(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
	:Leadable(map, car, driveplan, changer)
{
	msc = new MessageCard(50, 50, 30, GetColor(255, 255, 255), GetColor(30,30,30));
	ptemperBar = new Bar(0, 20,WND_X);

	MES_TODEP = msc->addPage("エンターキーを押して出発しよう");
	MES_ONTOP1 = msc->addPage("↑↑↑↑↑↑↑\nこれ、私の機嫌！キレさせたらおしまいね");
	MES_SPACE = msc->addPage("止まってる時だけ、スペースキーで渋滞情報が見られるよ");
	MES_BLIND = msc->addPage("ここ、違う。エンターキーで戻って");
	MES_TOOLONGSTOP = msc->addPage("止まりすぎ！早く動きなさいよ");
	MES_TEMPR09 = msc->addPage("快適だわ！私すごい機嫌いい！");
	MES_TEMPR03 = msc->addPage("・・・目的地はまだかしら");
	MES_TEMPR02 = msc->addPage("まだかーーい(怒)");
	MES_TEMPR01 = msc->addPage("かんにんぶくろの緒が キレそう");
	MES_LOW = msc->addPage("車の流れが遅い");
	MES_HIGH = msc->addPage("おぉ速い！景色が流れる流れる！");

	MES_NONE = msc->addPage("　");

	MES_GOSSIP[0]=msc->addPage("そういえばさ、");
	MES_GOSSIP[1] = msc->addPage("ソフトを作る作業を「プログラミング」って言うんだけど、");
	MES_GOSSIP[2] = msc->addPage("このゲームもプログラミングで作られたんだ！");
	MES_GOSSIP[3] = msc->addPage("この部活ではそのプログラミングを勉強できるんだよ");
	MES_GOSSIP[4] = msc->addPage("このゲームを作った人も勉強し続けてるんだ。\nパメルから言わせてもらうと、まだ下手くそだけど");
	MES_GOSSIP[5] = msc->addPage("ゲーム作りたい！そんな人は、ぜひこの学校のこのコンピュータ部へ！");
	MES_GOSSIP[6] = msc->addPage("え？運転中にむやみに話しかけるなって？\nごめんなさ～い、失礼しました～");
}

void DrivingLeader::update()
{
	//車更新
	remoteCar->update();
	//渋滞情報の表示の可不可
	remoteMap->setScreenTS(false);
	if (!remoteCar->isRunning())if (CheckHitKey(KEY_INPUT_SPACE)!=0)remoteMap->setScreenTS(true);
	//到着か否か判定
	if (remoteCar->getCurrentBranch() == drivePlan->goal) {
		changer->changeScene(Clear);
	}
	//ゲームオーバー判定
	if (Ptemper < 0)changer->changeScene(Over);

	//雑談
	if (drivingT ==1500) {
		gosippingT++;
		if (gosippingT == 10)msc->jumpTo(MES_GOSSIP[0]);
		if (gosippingT == 100)msc->jumpTo(MES_GOSSIP[1]);
		if (gosippingT == 250)msc->jumpTo(MES_GOSSIP[2]);
		if (gosippingT == 400)msc->jumpTo(MES_GOSSIP[3]);
		if (gosippingT == 580)msc->jumpTo(MES_GOSSIP[4]);
		if (gosippingT == 760)msc->jumpTo(MES_GOSSIP[5]);
		if (gosippingT == 940)msc->jumpTo(MES_GOSSIP[6]);
		if(gosippingT<1100)return;
	}

	drivingT++;

	if (Ptemper > 0.9)/*快適だわ！私すごい機嫌いい！*/msc->jumpTo(MES_TEMPR09);
	if (Ptemper < 0.3)/*・・・目的地はまだかしら*/msc->jumpTo(MES_TEMPR03);
	if (Ptemper < 0.2)/*まだかーーい(怒)*/msc->jumpTo(MES_TEMPR02);
	
	//パメル#1 出発からの経過時間判定
	Ptemper += - 0.0002;
	//パメル#2 止まりすぎ
	if (remoteCar->isRunning())stoppingT = 0; else stoppingT++;
	if (stoppingT > 90) { 
		/*止まりすぎ！早く動きなさいよ*/msc->jumpTo(MES_TOOLONGSTOP);
		Ptemper += (-0.001); }

	//パメル#3 違う行き止まり
	if (remoteCar->getCurrentBranch() != drivePlan->goal
		&&remoteCar->getCurrentPosition() != drivePlan->start
		&& remoteCar->canOnlyBack()
		&&!remoteCar->isRunning()) {
		if (wrongBlindSpotFlag == 0)
		{
			wrongBlindSpotFlag++;
			Ptemper += (-0.05);
			/*ここ、違う。エンターキーで戻って*/msc->jumpTo(MES_BLIND);
		}
	}else wrongBlindSpotFlag = 0;

	//パメル#4 のろのろ運転は嫌ですよ
	if (drivingT % 15 == 0) {///N秒おきに
		speedLog.push_back(remoteCar->getCurrentVelocity());///最近の変位を更新
		if (speedLog.size() > 13)speedLog.erase(speedLog.begin());///過去のものから消す
		displace = std::accumulate(speedLog.begin(), speedLog.end(), 0);
	}
	double displaceEvaluating=(displace-5)*0.00002;
	if (speedLog.size() > 8) Ptemper += displaceEvaluating;
	if (displaceEvaluating > 2) { highLasting++; lowLasting = 0; }
	if (displaceEvaluating < -2) { lowLasting++; highLasting = 0; }
	/*車の流れが遅い*/if (lowLasting == 180)msc->jumpTo(MES_LOW);
	/*おぉ速い！景色が流れる流れる！*/if (highLasting == 120)msc->jumpTo(MES_HIGH);
	/*無口になる*/if (lowLasting + highLasting < 30
		&&(msc->nowPage()==MES_HIGH||msc->nowPage()==MES_LOW))msc->jumpTo(MES_NONE);

	if (Ptemper < 0.1)/*かんにんぶくろの緒が キレそう*/msc->jumpTo(MES_TEMPR01);
	if (drivingT < 520)/*スペースキーで渋滞情報が見られるよ*/msc->jumpTo(MES_SPACE);
	if (drivingT < 400)/*これ、私の機嫌！*/msc->jumpTo(MES_ONTOP1);
	if (remoteCar->getCurrentPosition() == drivePlan->start)/*エンターキーを押して出発しよう*/msc->jumpTo(MES_TODEP);

	//パメル機嫌登録
	ptemperBar->setCurrent(Ptemper);
}

void DrivingLeader::draw()
{
	remoteCar->draw();
	ptemperBar->draw();
	msc->draw();
}

void DrivingLeader::drawAsMap()
{
	remoteMap->setWhatToDraw(MapWhatToDraw::ROADS_DRAW);
	remoteMap->drawOnMap();
	remoteCar->drawOnMap();
	remoteMap->setWhatToDraw(MapWhatToDraw::SPOTNAMES_DRAW);
	remoteMap->drawOnMap();
}

double DrivingLeader::getMapExr()
{
	return 1.0;
}

int DrivingLeader::getMapX()
{

	return WND_X*0.5+MAP_SCREEN_W*0.5*getMapExr()-remoteCar->getX()*getMapExr();
}

int DrivingLeader::getMapY()
{
	return WND_Y*0.5 + MAP_SCREEN_H*0.5*getMapExr() - remoteCar->getY()*getMapExr();
}

void Bar::setCurrent(double current)
{
	this->current = current>1.0?1.0: current;
}

void Bar::draw()
{
	DrawLine(x1, y, x1 + current * exr, y, GetColor(255, 0, 0), 8);
}

