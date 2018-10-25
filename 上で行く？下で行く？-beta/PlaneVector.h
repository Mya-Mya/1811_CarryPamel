#pragma once
namespace Mya {

	/*���ʃx�N�g���Ǘ��^�p�R���e�i
	���O��ԁFMya*/

	class PlaneVector
	{
	private:
		double X;
		double Y;
		double SquaringSize;//�傫���̓��
		long double Size;
		long double XperUnitSize;
		long double YperUnitSize;
		long double UnitMultiple;//�傫�����P�ɂ��邽�߂ɂ͎��g�����{�ɂ���΂悢�����i�[
		Mya::PlaneVector* SubtractionLeft = nullptr;
		Mya::PlaneVector* SubtractionRight = nullptr;
		void updateProperty();//�v���p�e�B���X�V
	public:
		/*���g�̃x�N�g���̗v�f�Ɗ�{�v���p�e�B*/

		//�x�N�g���̐������w��(x,y)
		void setComponent(double, double);
		//�x�N�g����x�������w��
		void setX(double);
		//�x�N�g����y�������w��
		void setY(double);
		//�x�N�g���̑傫����Ԃ�
		double size();
		//x������Ԃ�
		double x() { return X; };
		//y������Ԃ�
		double y() { return Y; };
		/*�[���x�N�g��*/

		//�[���x�N�g���ɂ���
		void setZero();
		//�[���x�N�g�����ǂ�����Ԃ�
		bool isZero() { return Size == 0; };
		/*�傫���𑀍삷��*/

		//�w��̑傫���̎���x������Ԃ�
		double scalarMultipleX(double);
		//�w��̑傫���̎���y������Ԃ�
		double scalarMultipleY(double);
		//�w��̑傫���̎��̎��g�̃x�N�g����Ԃ�
		Mya::PlaneVector* getScalarMultipleVector(double);
		/*�����𑀍삷��*/
		//���g�̋t�x�N�g����Ԃ�
		Mya::PlaneVector* getInverse();
		//���g���t�]������
		void invert();
		/*�x�N�g���̉��Z*/

		//���̃x�N�g���Ƃ̉��Z����x������Ԃ�
		double x(Mya::PlaneVector*);
		//���̃x�N�g���Ƃ̉��Z����y������Ԃ�
		double y(Mya::PlaneVector*);
		//���Ӄx�N�g�� - �E�Ӄx�N�g�� �����g�ɓK�p
		void setSubtraction(Mya::PlaneVector*, Mya::PlaneVector*);
		//setSubtraction�ɂēo�^���� ���Ӄx�N�g�� - �E�Ӄx�N�g�� ���X�V���A���g�ɓK�p�@�G���[����false��Ԃ�
		bool updateSubtraction();
		/*���[�e�B���e�B*/
		//�R���X�g���N�^
		PlaneVector() {};
		//�x�N�g���̐������w�肵�ăR���X�g���N�^(x,y)
		PlaneVector(double, double);
	};
}