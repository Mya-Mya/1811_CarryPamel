#include "Singleton.h"
#include"DxLib.h"

void Keyboard::Update()
{
	char tmpKey[256];             // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);  // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			m_Key[i]++;   // ���Z
		}
		else {              // ������Ă��Ȃ����
			m_Key[i] = 0; // 0�ɂ���
		}
	}
}

int Keyboard::Get(int KeyCode)
{
	return m_Key[KeyCode]; // KeyCode�̓��͏�Ԃ�Ԃ�
}

Mouse::Mouse() :
	mX(0)
	, mY(0)
{
	memset(mKeyPressingCount, 0, sizeof(mKeyPressingCount));
	memset(mKeyReleasingCount, 0, sizeof(mKeyReleasingCount));
}

//�X�V
bool Mouse::Update() {
	int nowInput = GetMouseInput();      //���̃L�[�̓��͏�Ԃ��擾
	for (int i = 0; i<BUTTON_NUM; i++) {
		if ((nowInput >> i) & 0x01) {    //i�Ԃ̃L�[��������Ă�����
			if (mKeyReleasingCount[i] > 0) {//������J�E���^��0���傫�����
				mKeyReleasingCount[i] = 0;   //0�ɖ߂�
			}
			mKeyPressingCount[i]++;          //������J�E���^�𑝂₷
		}
		else {                             //i�Ԃ̃L�[��������Ă�����
			if (mKeyPressingCount[i] > 0) { //������J�E���^��0���傫�����
				mKeyPressingCount[i] = 0;    //0�ɖ߂�
			}
			mKeyReleasingCount[i]++;         //������J�E���^�𑝂₷
		}
	}
	GetMousePoint(&mX, &mY);
	return true;
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int Mouse::GetPressingCount(int keyCode) {
	if (!Mouse::IsAvailableCode(keyCode)) {
		return -1;
	}
	return mKeyPressingCount[keyCode];
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int Mouse::GetReleasingCount(int keyCode) {
	if (!Mouse::IsAvailableCode(keyCode)) {
		return -1;
	}
	return mKeyReleasingCount[keyCode];
}

//keyCode���L���Ȓl���`�F�b�N����
bool Mouse::IsAvailableCode(int keyCode) {
	if (0 <= keyCode && keyCode<BUTTON_NUM) {
		return true;
	}
	return false;
}

int Mouse::GetX() {
	return mX;
}

int Mouse::GetY() {
	return mY;
}
