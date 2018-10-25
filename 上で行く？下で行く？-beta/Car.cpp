#include "Car.h"
#include"DxLib.h"
#include<iostream>
#include"Frame.h"
#include"Config.h"
#include"TurnDirection.h"
#include"Singleton.h"
#include<math.h>
#pragma warning(disable:4244)
using namespace std;

void Car::init()
{
	//車方向ベクトル
	CarHeadding = new Mya::PlaneVector();
	CarHeadding->setZero();
	//車の画像
	CarImage = LoadGraph("Image/CarImage.png");

	//方向転換を司るボタン
	int ToggleW = 100, ToggleH = 100, ToggleY = WND_Y - ToggleH,
		ToggleXStarting = WND_X / 2 - (ToggleW * 3) / 2,
		ToggleFontSize = 40;
	Toggles[ToggleLeft] = new Toggle(ToggleXStarting + ToggleW * 0, ToggleY, ToggleW, ToggleH, "←左", ToggleFontSize, KEY_INPUT_LEFT);
	Toggles[ToggleStraight] = new Toggle(ToggleXStarting + ToggleW * 1, ToggleY, ToggleW, ToggleH, "↑\n前", ToggleFontSize, KEY_INPUT_UP);
	Toggles[ToggleRight] = new Toggle(ToggleXStarting + ToggleW * 2, ToggleY, ToggleW, ToggleH, "右→", ToggleFontSize, KEY_INPUT_RIGHT);
	for (int i = 0; i < 3; i++)Toggles[i]->addActionListener(this);
}


void Car::turn(TurnDirection td)
{
	BeforePosition = NowPosition;
	NowPosition = NowPosition->turn(td);

	CarMovingL = 0;
	running = true;

	setCarHeadding(BeforePosition, NowPosition);
	setCarVelocity(NowPosition->getTS());
}

void Car::setCarHeadding(Point * before, Point * now)
{
	CarHeadding->setComponent(
		now->getX() - before->getX(),
		now->getY() - before->getY()
	);
}

void Car::setCarVelocity(TrafficState ts)
{
	this->MyTS = ts;
	switch (ts)
	{
	case Green:
		CarVelocity= 3;
		break;
	case Orange:
		CarVelocity = 2;
		break;
	case Red:
		CarVelocity = 1;
		break;
	case Purple:
		CarVelocity = 0.5;
		break;
	case TrafficState_None:
		CarVelocity = 4;
		break;
	}
}

void Car::draw()
{
	if (NowPosition == nullptr)return;
	for (int i = 0; i < 3; i++)Toggles[i]->draw();
}

TurnDirection Car::availableOnlyOneFork(Point * point)
{
	if (point->canTurn(Right) + point->canTurn(Left) + point->canTurn(Straight) == 1) {
		for(TurnDirection i:{Right,Left,Straight})
			if (NowPosition->canTurn(i)) {
				return TurnDirection(i);
		}
	}
	return TurnDirection_None;
}

void Car::update()
{
	if (NowPosition == nullptr)return;
	running = CarMovingL < CarHeadding->size();
	if(!isRunning())//停止中
	{
		Toggles[ToggleLeft]->setAvailable(NowPosition->canTurn(Left));
		Toggles[ToggleStraight]->setAvailable(NowPosition->canTurn(Straight));
		Toggles[ToggleRight]->setAvailable(NowPosition->canTurn(Right));

		if (canOnlyBack()) {//後退しかできない
			if (Keyboard::Instance()->Get(KEY_INPUT_RETURN) != 0)turn(Back);
		}else 
			if (availableOnlyOneFork(NowPosition) !=TurnDirection_None) {//先へ進める方向が1つしかない
				turn(availableOnlyOneFork(NowPosition));
		} 
	}
	else {//移動中
		CarMovingL += CarVelocity;
		for (int i = 0; i < 3; i++)Toggles[i]->setAvailable(false);
	}
	
	for (int i = 0; i < 3; i++)Toggles[i]->update();
}

int Car::getX()
{
	return BeforePosition->getX() + CarHeadding->scalarMultipleX(CarMovingL);
}

int Car::getY()
{
	return BeforePosition->getY() + CarHeadding->scalarMultipleY(CarMovingL);
}

void Car::actionPerformed(EventObj * e)
{
	if (!isRunning()) {//停止中
		if (e == Toggles[ToggleStraight])turn(Straight);
		if (e == Toggles[ToggleRight])turn(Right);
		if (e == Toggles[ToggleLeft])turn(Left);
	}
}

void Car::drawOnMap()
{
	DrawRotaGraph(
		BeforePosition->getX() + CarHeadding->scalarMultipleX(CarMovingL),
		BeforePosition->getY() + CarHeadding->scalarMultipleY(CarMovingL),
		0.3,
		atan2(CarHeadding->x(), -CarHeadding->y()),
	CarImage, TRUE);
}

double Car::getCurrentVelocity()
{
	return isRunning()? CarVelocity:0;
}

Point * Car::getCurrentPosition()
{
	return isRunning()?nullptr:NowPosition;
}

iBranch * Car::getCurrentBranch()
{
	return isRunning()?nullptr:NowPosition->getBranch();
}

bool Car::canOnlyBack()
{
	return (!NowPosition->canTurn(Right) &&
		!NowPosition->canTurn(Left) &&
		!NowPosition->canTurn(Straight) &&
		NowPosition->canTurn(Back));
}

bool Car::isRunning()
{
	return running;
}

void Car::setPosition(Point *position)
{
	NowPosition = position;
	BeforePosition = NowPosition;
}