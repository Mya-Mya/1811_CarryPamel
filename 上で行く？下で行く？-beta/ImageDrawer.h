#pragma once
#include"MyaObject.h"

class ImageDrawer :public MyaO {
private:
	int MyImageHandle;
	int x, y;
	double Ext;
public:
	void init() {};
	void loadGraph(char* filePath, int w, int h);
	void setPos(int x, int y);
	void update() {};
	void draw();
};