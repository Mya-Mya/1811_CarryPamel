#include "IntroLeader.h"
#include"DxLib.h"
#include"Singleton.h"
#include"WhatToDraw.h"
#include"Config.h"

IntroLeader::IntroLeader(MapData * map, Car * car,DrivePlan *driveplan,SceneChangable *changer)
	:SceneLeadable(map,car,driveplan,changer)
{
	message = new MessageCard(50, 50, 25, GetColor(240, 240, 240), GetColor(40, 40, 40));
	message->addPage("�ǂ����B���̃Q�[���̐i�s��S������");
	message->addPage("���Ȃ��̗F�l���אl�ɂ�����l���A�p�����Ɛ\��");
	MES_SHOWSTART=message->addPage("���B�͍����̏ꏊ�ɂ���V���b�s���O���[����");
	message->addPage("�u�E�B���h�E�V���b�s���O�v������̂�n(������)��ł���");
	message->addPage("���̓V���b�s���O���[�����o�āA�p�����Ƃ��Ȃ��͒��ԏ�ɂ���");
	message->addPage("���A�p�����͂��Ȃ��̎Ԃɏ���Ă��̃V���b�s���O���[���܂ŗ���");
	message->addPage("���Ȃ��͋A��݂̂�������Ȃ����A���͈Ⴄ");
	MES_SHOWGOAL=message->addPage("���A�p�����͂��ꂩ�炱�̊X�ɏ��X�p��������");
	message->addPage("���������̏�ɂ͂��Ȃ��̎Ԃ����Ȃ�");
	message->addPage("���萔�Ȃ̂����A�p���������̏ꏊ�܂ŏ悹�Ă���Ȃ���");
	message->addPage("�\����Ȃ��̂����A���Ԃ������̂�");
	message->addPage("���H�����u����޳�����ݸށv��؂�グ��Ηǂ��������ƁI�H");
	message->addPage("����͏\�����m�����A�p�����ɂ͂��̂悤�Ȃ��Ƃ͂ł���");
	message->addPage("����A�����Ɂu����޳�����ݸށv���d�v�ȕ����ł��邩�A�m��Ȃ��̂�");
	message->addPage("�i���{�A�v���P�[�V�����J����(5�N�{��)���悭�m��܂���j");
	message->addPage("�܂��悢�B��芸�������}�̌��A���Ȃ��ɗ��ށB���肪�Ƃ�");
	message->addPage("�y�ǂ�Łz�����烋�[���Ǝd�g�݂��������B�悭�ǂނ悤��");
	message->addPage("(1)�Ȃ�ׂ�������������悤�ɁB���Ԃ��o��������ƁE�E�E");
	message->addPage("(2)�Ԃ͌����_�Ŏ~�܂��Ă���ԂɁA�E�������܂����������u���L�[�v�Ŏw��ł���");
	message->addPage("(3)�����Ƃ������͌�ނ��ł���B����́u�G���^�[�L�[�v�Ŏw��ł���");
	message->addPage("(4)��ʏa�؂Ƃ������̂����݂��A���݋�ɂ��Ԃ̑��x���ς��");
	message->addPage("�������A��ʏa�؂͂���������킯�ł͂Ȃ�");
	message->addPage("���s���́A���Ȃ��͎Ԃ��^�]����̂�����A�O�����Ă��Ȃ���΂Ȃ�Ȃ�");
	message->addPage("(5)�~�܂��Ă���Ԃ����A�u�X�y�[�X�L�[�v�������Ό�ʏa�؂��݂���");
	message->addPage("(6)�Q�[�����͖ړI�n�ł���Ƃ����}�[�N�͕\������Ȃ�");
	message->addPage("�ȏゾ�B���Ԃ��Ȃ��̂ō������o�����Ă���");
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
