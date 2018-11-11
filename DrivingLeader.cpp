
#include "DrivingLeader.h"
#include"Singleton.h"
#include"DxLib.h"
#include<numeric>

DrivingLeader::DrivingLeader(MapData * map, Car * car, DrivePlan * driveplan, SceneChangable * changer)
	:Leadable(map, car, driveplan, changer)
{
	msc = new MessageCard(50, 50, 30, GetColor(255, 255, 255), GetColor(30,30,30));
	ptemperBar = new Bar(0, 20,WND_X);

	MES_TODEP = msc->addPage("�G���^�[�L�[�������ďo�����悤");
	MES_ONTOP1 = msc->addPage("��������������\n����A���̋@���I�L���������炨���܂���");
	MES_SPACE = msc->addPage("�~�܂��Ă鎞�����A�X�y�[�X�L�[�ŏa�؏�񂪌������");
	MES_BLIND = msc->addPage("�����A�Ⴄ�B�G���^�[�L�[�Ŗ߂���");
	MES_TOOLONGSTOP = msc->addPage("�~�܂肷���I���������Ȃ�����");
	MES_TEMPR09 = msc->addPage("���K����I���������@�������I");
	MES_TEMPR03 = msc->addPage("�E�E�E�ړI�n�͂܂�������");
	MES_TEMPR02 = msc->addPage("�܂����[�[��(�{)");
	MES_TEMPR01 = msc->addPage("����ɂ�Ԃ���̏��� �L������");
	MES_LOW = msc->addPage("�Ԃ̗��ꂪ�x��");
	MES_HIGH = msc->addPage("���������I�i�F������闬���I");

	MES_NONE = msc->addPage("�@");

	MES_GOSSIP[0]=msc->addPage("���������΂��A");
	MES_GOSSIP[1] = msc->addPage("�\�t�g������Ƃ��u�v���O���~���O�v���Č����񂾂��ǁA");
	MES_GOSSIP[2] = msc->addPage("���̃Q�[�����v���O���~���O�ō��ꂽ�񂾁I");
	MES_GOSSIP[3] = msc->addPage("���̕����ł͂��̃v���O���~���O��׋��ł���񂾂�");
	MES_GOSSIP[4] = msc->addPage("���̃Q�[����������l���׋��������Ă�񂾁B\n�p�������猾�킹�Ă��炤�ƁA�܂����肭��������");
	MES_GOSSIP[5] = msc->addPage("�Q�[����肽���I����Ȑl�́A���Ђ��̊w�Z�̂��̃R���s���[�^���ցI");
	MES_GOSSIP[6] = msc->addPage("���H�^�]���ɂނ�݂ɘb��������Ȃ��āH\n���߂�Ȃ��`���A���炵�܂����`");
}

void DrivingLeader::update()
{
	//�ԍX�V
	remoteCar->update();
	//�a�؏��̕\���̉s��
	remoteMap->setScreenTS(false);
	if (!remoteCar->isRunning())if (CheckHitKey(KEY_INPUT_SPACE)!=0)remoteMap->setScreenTS(true);
	//�������ۂ�����
	if (remoteCar->getCurrentBranch() == drivePlan->goal) {
		changer->changeScene(Clear);
	}
	//�Q�[���I�[�o�[����
	if (Ptemper < 0)changer->changeScene(Over);

	//�G�k
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

	if (Ptemper > 0.9)/*���K����I���������@�������I*/msc->jumpTo(MES_TEMPR09);
	if (Ptemper < 0.3)/*�E�E�E�ړI�n�͂܂�������*/msc->jumpTo(MES_TEMPR03);
	if (Ptemper < 0.2)/*�܂����[�[��(�{)*/msc->jumpTo(MES_TEMPR02);
	
	//�p����#1 �o������̌o�ߎ��Ԕ���
	Ptemper += - 0.0002;
	//�p����#2 �~�܂肷��
	if (remoteCar->isRunning())stoppingT = 0; else stoppingT++;
	if (stoppingT > 90) { 
		/*�~�܂肷���I���������Ȃ�����*/msc->jumpTo(MES_TOOLONGSTOP);
		Ptemper += (-0.001); }

	//�p����#3 �Ⴄ�s���~�܂�
	if (remoteCar->getCurrentBranch() != drivePlan->goal
		&&remoteCar->getCurrentPosition() != drivePlan->start
		&& remoteCar->canOnlyBack()
		&&!remoteCar->isRunning()) {
		if (wrongBlindSpotFlag == 0)
		{
			wrongBlindSpotFlag++;
			Ptemper += (-0.05);
			/*�����A�Ⴄ�B�G���^�[�L�[�Ŗ߂���*/msc->jumpTo(MES_BLIND);
		}
	}else wrongBlindSpotFlag = 0;

	//�p����#4 �̂�̂�^�]�͌��ł���
	if (drivingT % 15 == 0) {///N�b������
		speedLog.push_back(remoteCar->getCurrentVelocity());///�ŋ߂̕ψʂ��X�V
		if (speedLog.size() > 13)speedLog.erase(speedLog.begin());///�ߋ��̂��̂������
		displace = std::accumulate(speedLog.begin(), speedLog.end(), 0);
	}
	double displaceEvaluating=(displace-5)*0.00002;
	if (speedLog.size() > 8) Ptemper += displaceEvaluating;
	if (displaceEvaluating > 2) { highLasting++; lowLasting = 0; }
	if (displaceEvaluating < -2) { lowLasting++; highLasting = 0; }
	/*�Ԃ̗��ꂪ�x��*/if (lowLasting == 180)msc->jumpTo(MES_LOW);
	/*���������I�i�F������闬���I*/if (highLasting == 120)msc->jumpTo(MES_HIGH);
	/*�����ɂȂ�*/if (lowLasting + highLasting < 30
		&&(msc->nowPage()==MES_HIGH||msc->nowPage()==MES_LOW))msc->jumpTo(MES_NONE);

	if (Ptemper < 0.1)/*����ɂ�Ԃ���̏��� �L������*/msc->jumpTo(MES_TEMPR01);
	if (drivingT < 520)/*�X�y�[�X�L�[�ŏa�؏�񂪌������*/msc->jumpTo(MES_SPACE);
	if (drivingT < 400)/*����A���̋@���I*/msc->jumpTo(MES_ONTOP1);
	if (remoteCar->getCurrentPosition() == drivePlan->start)/*�G���^�[�L�[�������ďo�����悤*/msc->jumpTo(MES_TODEP);

	//�p�����@���o�^
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

