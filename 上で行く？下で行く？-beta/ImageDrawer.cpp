#include "ImageDrawer.h"
#include"DxLib.h"


void ImageDrawer::loadGraph(char * filePath, int w, int h)
{
	this->MyImageHandle = LoadGraph(filePath, TRUE);
	int picX, picY;
	GetGraphSize(MyImageHandle, &picX, &picY);
	Ext = (double)w / (double)picX;
	Ext = (Ext < (double)h / (double)picY) ? (double)h / (double)picY : Ext;
}

void ImageDrawer::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void ImageDrawer::draw()
{
	DrawRotaGraph(x, y, Ext, 0, MyImageHandle, TRUE);
}
