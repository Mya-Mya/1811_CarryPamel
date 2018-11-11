#include "PlaneVector.h"
#include<iostream>
using namespace std;
#include<math.h>


Mya::PlaneVector::PlaneVector(double x, double y)
{
	setComponent(x, y);
}

void Mya::PlaneVector::updateProperty()
{
	if (SubtractionLeft != nullptr && SubtractionRight != nullptr) {
		X = SubtractionLeft->x() - SubtractionRight->x();
		Y = SubtractionLeft->y() - SubtractionRight->y();
	}

	SquaringSize = pow(X, 2) + pow(Y, 2);
	Size = sqrt(SquaringSize);

	if (isZero())return;//#DIV/0! –hŽ~

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

void Mya::PlaneVector::setZero()
{
	X = 0;
	Y = 0;
	updateProperty();
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
