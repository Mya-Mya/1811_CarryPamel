#pragma once
#include"WhatToDraw.h"
class MapDrawable {
public:
	virtual void setWhatToDraw(MapWhatToDraw) {};
	virtual void drawOnMap() = 0;
};