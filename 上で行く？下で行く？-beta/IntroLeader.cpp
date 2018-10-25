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
	prevPage = new Toggle(ToggleXStarting, ToggleY, ToggleW, ToggleH, "���O", ToggleFontSize, KEY_INPUT_LEFT);
	prevPage->addActionListener(this);
	nextPage = new Toggle(ToggleXStarting + ToggleW, ToggleY, ToggleW, ToggleH, "����", ToggleFontSize, KEY_INPUT_RIGHT);
	nextPage->addActionListener(this);

	msc = new MessageCard(20, WND_Y-140, 30, GetColor(240, 240, 240), GetColor(40, 40, 40));
	msc->addPage("���́A���̃Q�[���̐i�s��S������");
	msc->addPage("���Ȃ��̗F�l�A�p�����Ɛ\��");
	MES_SHOWSTART=msc->addPage("�������́A�����̐Ԃ��܂�̏���");
	msc->addPage("�V���b�s���O���[���ł̂����������y����ł���\n���y���������ˁI");
	msc->addPage("���͋A��Ƃ���B�������͒��ԏ�ɂ���");
	msc->addPage("�p�����́A���Ȃ��̎Ԃɏ���Ă����֗���");
	msc->addPage("���Ȃ��͋A��݂̂�������Ȃ����A���͈Ⴄ");
	MES_SHOWGOAL=msc->addPage("���ꂩ��A�p�����͂��̐��ۂ̏��ɗp��������");
	msc->addPage("�s���Ȃ��Ⴂ���Ȃ�\n�ł��A�����ɂ͂��Ȃ��̎Ԃ����Ȃ�");
	msc->addPage("���萔�Ȃ̂����A���������܂ő����Ă���Ȃ���");
	msc->addPage("���肪�Ƃ��B�N�͗D�����ˁB��낵�����ނ�");
	msc->addPage("�y�悭�ǂ�Łz���ꂶ�Ⴀ�A���[�����������");
	msc->addPage("(1)����{�点�Ă͂����Ȃ��B\n��ʏ�̕��Ɏ��̋@�����\�������");
	msc->addPage("�@�����[���ɂȂ����玄�͓{��B\n��������Q�[���I�[�o�[���I");
	msc->addPage("���̋@�����Ƃ���@��4����");
	msc->addPage("�ЂƂ́A�����������邱��\n�����Ăӂ��߂́E�E�E");
	msc->addPage("�����܂��[�[��\n�������Ⴄ�Ƃ��̃Q�[�����ʔ����Ȃ������");
	msc->addPage("�^�]���Ă邤���ɕ�����悫����\n�����悭�ώ@���Ă悭�l���邱�ƂˁI");
	msc->addPage("(2)�����_�Ŏ~�܂��Ă���ԂɁA\n�u���L�[�v�Ői�ޕ���������ׂ�B");
	msc->addPage("(3)�����ǂ܂�ɗ�����A�u�G���^�[�L�[�v�Ŗ߂��B");
	msc->addPage("(4)�a�؂�����A���݋�ɂ���ĎԂ̑������ς��");
	msc->addPage("(5)�u�X�y�[�X�L�[�v�������Ώa�؂��݂���B\n�������~�܂��Ă��鎞����");
	msc->addPage("���H��ʖ@��71���5����5 �ɂ����邯��\n����Ȃ���͏a�،���̂͊�Ȃ��B�^�]�W���������I");
	msc->addPage("(6)�^�]���͐Ԃ��ۂ���ۂ͕\������Ȃ�\n�ړI�n�������Ɗo���Ă�������");
	msc->addPage("���[���͕��������H�Ō�ɁA�n�}�S�̂��m�F���Ă˂���");
	msc->addPage("�u���v�Ŏ���");
	MES_PUSHTODEP=msc->addPage("����ł́A�o���i�s�I�I\n�Ԃ��o���A���ړI�n�I");

	//message->jumpTo(MES_PUSHTODEP);
}

void IntroLeader::update()
{
	if (msc->isEnd())changer->changeScene(Driving);
	nextPage->update();
	prevPage->update();
	if (msc->nowPage() == MES_PUSHTODEP)nextPage->setText("�o����");
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
	if (e == prevPage) { msc->prevPage(); nextPage->setText("����"); }
}
