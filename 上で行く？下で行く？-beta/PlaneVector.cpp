#include "PlaneVector.h"
#include<iostream>
using namespace std;
#include<math.h>


Mya::PlaneVector::PlaneVector()
{
	cout << "Mya 平面ベクトル管理運用コンテナ引数なし "<< this << " 作成" <<endl ;
}

Mya::PlaneVector::PlaneVector(double x, double y)
{
	cout << "Mya 平面ベクトル管理運用コンテナ引数あり " << this << " 作成" << endl;
	setComponent(x, y);
}


Mya::PlaneVector::~PlaneVector()
{
	cout << "Mya 平面ベクトル管理運用コンテナ " << this << " 消滅" << endl;
}


void Mya::PlaneVector::updateProperty()
{
	if (SubtractionLeft != nullptr && SubtractionRight != nullptr) {
		X = SubtractionLeft->x() - SubtractionRight->x();
		Y = SubtractionLeft->y() - SubtractionRight->y();
	}

	SquaringSize = pow(X, 2) + pow(Y, 2);
	Size = sqrt(SquaringSize);

	if (isZero())return;//#DIV/0! 防止

	UnitMultiple = sqrt(1 / SquaringSize);
	XperUnitSize = X * UnitMultiple;
	YperUnitSize = Y * UnitMultiple;
}

void Mya::PlaneVector::setComponent(double x, double y)
{
	X = x;
	Y = y;
	updateProperty();
}

void Mya::PlaneVector::setX(double x)
{
	X = x;
	updateProperty();
}

void Mya::PlaneVector::setY(double y)
{
	Y = y;
	updateProperty();
}

double Mya::PlaneVector::size()
{
	return Size;
}

double Mya::PlaneVector::x()
{
	return X;
}

double Mya::PlaneVector::y()
{
	return Y;
}

void Mya::PlaneVector::setZero()
{
	X = 0;
	Y = 0;
	updateProperty();
}

bool Mya::PlaneVector::isZero()
{
	return (Size==0);
}

double Mya::PlaneVector::scalarMultipleX(double l)
{
	return XperUnitSize * l;
}

double Mya::PlaneVector::scalarMultipleY(double l)
{
	return YperUnitSize * l;
}

Mya::PlaneVector * Mya::PlaneVector::getScalarMultipleVector(double l)
{
	return new Mya::PlaneVector(XperUnitSize*l,YperUnitSize*l);
}

Mya::PlaneVector * Mya::PlaneVector::getInverse()
{
	return new Mya::PlaneVector(-X,-Y);
}

void Mya::PlaneVector::invert()
{
	X *= -1;
	Y *= -1;
	updateProperty();
}

double Mya::PlaneVector::x(Mya::PlaneVector *other)
{
	return X+other->x();
}

double Mya::PlaneVector::y(Mya::PlaneVector *other)
{
	return Y + other->y();
}

void Mya::PlaneVector::setSubtraction(Mya::PlaneVector *left, Mya::PlaneVector *right)
{
	SubtractionLeft = left;
	SubtractionRight = right;
	updateProperty();
}

bool Mya::PlaneVector::updateSubtraction()
{
	if (SubtractionLeft == nullptr || SubtractionRight == nullptr)return false;
	updateProperty();
	return true;
}
