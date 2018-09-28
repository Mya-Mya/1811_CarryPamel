#pragma once
#include"Point.h"
#include"iBranch.h"
class DrivePlan {
public:
	DrivePlan(Point *start, iBranch *goal) {
		this->start = start;
		this->goal = goal;
	}
	Point*start;
	iBranch*goal;
};