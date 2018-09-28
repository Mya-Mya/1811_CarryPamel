#include "Car.h"
#include"DxLib.h"
#include<iostream>
#include"Frame.h"
#include"TurnDirection.h"
#include"Singleton.h"
#include<math.h>
#pragma warning(disable:4244)
using namespace std;

void Car::init()
{
	//é‘ï˚å¸ÉxÉNÉgÉã
	CarHeadding = new Mya::PlaneVector();
	CarHeadding->setZero();
	//é‘ÇÃâÊëú
	CarImage = LoadGraph("Image/CarImage.png");

	//ï˚å¸ì]ä∑ÇéiÇÈÉ{É^Éì
	int ToggleW = 100, ToggleH = 100, ToggleY = Frame::Height - ToggleH,
		ToggleXStarting = Frame::Width / 2 - (ToggleW * 3) / 2;
	Toggles[ToggleLeft] = new Toggle(ToggleXStarting + ToggleW * 0, ToggleY, ToggleW, ToggleH, "ç∂", 100, KEY_INPUT_LEFT);
	Toggles[ToggleStraight] = new Toggle(ToggleXStarting + ToggleW * 1, ToggleY, ToggleW, ToggleH, "ëO", 100, KEY_INPUT_UP);
	Toggles[ToggleRight] = new Toggle(ToggleXStarting + ToggleW * 2, ToggleY, ToggleW, ToggleH, "âE", 100, KEY_INPUT_RIGHT);
	for (int i = 0; i < 3; i++)Toggles[i]->addActionListener(this);
}


void Car::turn(TurnDirection td)
{
	BeforePosition = NowPosition;
	NowPosition = NowPosition->turn(td);

	CarMovingL = 0;
	running = false;

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
		CarVelocity = 2.3;
		break;
	case Red:
		CarVelocity = 1.2;
		break;
	case Winered:
		CarVelocity = 0.9;
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
	if(!isRunning())//í‚é~íÜ
	{
		Toggles[ToggleLeft]->setAvailable(NowPosition->canTurn(Left));
		Toggles[ToggleStraight]->setAvailable(NowPosition->canTurn(Straight));
		Toggles[ToggleRight]->setAvailable(NowPosition->canTurn(Right));

		if (canOnlyBack()) {//å„ëﬁÇµÇ©Ç≈Ç´Ç»Ç¢
			if (Keyboard::Instance()->Get(KEY_INPUT_RETURN) != 0)turn(Back);
		}else 
			if (availableOnlyOneFork(NowPosition) !=TurnDirection_None) {//êÊÇ÷êiÇﬂÇÈï˚å¸Ç™1Ç¬ÇµÇ©Ç»Ç¢
			for (TurnDirection i : {Right, Left, Straight}) {
				if (NowPosition->canTurn(i)) {
					turn(TurnDirection(i));
					break;
				}
			}
		} 
	}
	else {//à⁄ìÆíÜ
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
	if (CarMovingL >= CarHeadding->size()) {//í‚é~íÜ
		if (e == Toggles[ToggleStraight])turn(Straight);
		if (e == Toggles[ToggleRight])turn(Right);
		if (e == Toggles[ToggleLeft])turn(Left);
	}
}

void Car::drawOnMap()
{
	DrawRotaGraph(
		BeforePosition->getX() + CarHeadding->scalarMultipleX(CarMovingL),
		BeforePosition->getY() + CarHeadding->scalarMultipleY(CarMovingL),/*this->x this->y*/
		0.3,
		atan2(CarHeadding->x(), -CarHeadding->y()),
	CarImage, TRUE);
}

//îpé~ó\íË
void Car::setDriveable(bool driveable)
{
	if (!driveable)CarVelocity = 0;
	if (driveable)setCarVelocity(MyTS);
}

double Car::getCurrentVelocity()
{
	return CarVelocity;
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