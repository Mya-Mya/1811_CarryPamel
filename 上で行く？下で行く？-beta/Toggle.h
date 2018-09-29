#pragma once
#include "EventObj.h"
#include"MyaObject.h"
#include<string.h>
using namespace std;

class Toggle :public EventObj
	,MyaO
{
private:
	int x, y, h, w;
	string text;
	int textsize, textX, textY;
	int font;
	int casingKeyNum;
	bool available = true;
	int  availableTextCol, unavailableTextCol,availableBgCol,unavailableBgCol;
public:
	Toggle(int x, int y, int w, int h,string text,int textsize,int casingKeyNum);
	void init() {};
	void setAvailable(bool available);
	void update();
	void draw();
};

