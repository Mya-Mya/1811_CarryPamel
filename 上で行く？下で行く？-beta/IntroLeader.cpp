#include "IntroLeader.h"
#include"DxLib.h"
#include"Singleton.h"
#include"WhatToDraw.h"
#include"Config.h"

IntroLeader::IntroLeader(MapData * map, Car * car)
	:SceneLeadable(map,car)
{
	message = new MessageCard(50, 50);
	message->add("�ǂ����B���̃Q�[���̐i�s��S������");
	message->add("���Ȃ��̗F�l���אl�ɂ�����l���A�p�����Ɛ\��");
	/*Index=2*/message->add("���B�͍����̏ꏊ�ɂ���V���b�s���O���[����");
	message->add("�u�E�B���h�E�V���b�s���O�v������̂�n(������)��ł���");
	message->add("���̓V���b�s���O���[�����o�āA�p�����Ƃ��Ȃ��͒��ԏ�ɂ���");
	message->add("���A�p�����͂��Ȃ��̎Ԃɏ���Ă��̃V���b�s���O���[���܂ŗ���");
	message->add("���Ȃ��͋A��݂̂�������Ȃ����A���͈Ⴄ");
	/*Index=7*/message->add("���A�p�����͂��ꂩ�炱�̊X�ɏ��X�p��������");
	message->add("���������̏�ɂ͂��Ȃ��̎Ԃ����Ȃ�");
	message->add("���萔�Ȃ̂����A�p���������̏ꏊ�܂ŏ悹�Ă���Ȃ���");
	message->add("�\����Ȃ��̂����A���Ԃ������̂�");
	message->add("���H�����u����޳�����ݸށv��؂�グ��Ηǂ��������ƁI�H");
	message->add("����͏\�����m�����A�p�����ɂ͂��̂悤�Ȃ��Ƃ͂ł���");
	message->add("����A�����Ɂu����޳�����ݸށv���d�v�ȕ����ł��邩�A�m��Ȃ��̂�");
	message->add("�i���{�A�v���P�[�V�����J����(5�N�{��)���悭�m��܂���j");
	message->add("�܂��悢�B��芸�������}�̌��A���Ȃ��ɗ��ށB���肪�Ƃ�");
	message->add("�y�ǂ�Łz�����烋�[���Ǝd�g�݂��������B�悭�ǂނ悤��");
	message->add("(1)�Ȃ�ׂ�������������悤�ɁB���Ԃ��o��������ƁE�E�E");
	message->add("(2)�Ԃ͌����_�Ŏ~�܂��Ă���ԂɁA�E�������܂����������u���L�[�v�Ŏw��ł���");
	message->add("(3)�����Ƃ������͌�ނ��ł���B����́u�G���^�[�L�[�v�Ŏw��ł���");
	message->add("(4)��ʏa�؂Ƃ������̂����݂��A���݋�ɂ��Ԃ̑��x���ς��");
	message->add("�������A��ʏa�؂͂���������킯�ł͂Ȃ�");
	message->add("���s���́A���Ȃ��͎Ԃ��^�]����̂�����A�O�����Ă��Ȃ���΂Ȃ�Ȃ�");
	message->add("(5)�~�܂��Ă���Ԃ����A�u�X�y�[�X�L�[�v�������Ό�ʏa�؂��݂���");
	message->add("(6)�Q�[�����͖ړI�n�ł���Ƃ����}�[�N�͕\������Ȃ�");
	message->add("�ȏゾ�B���Ԃ��Ȃ��̂ō������o�����Ă��� indexOf 25");
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
	//�Ԃ͕`�悵�Ȃ���
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
