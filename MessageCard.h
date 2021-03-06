#pragma once
#include"MyaObject.h"
#include<vector>
#include<string>
using namespace std;

class MessageCard:public MyaO
{
private:
	int x, y;
	int xMargin = 20, yMargin = 10;
	int xText=0, yText = 0;

	int textCol, bgCol;

	int font;
	int pageIndex=0;
	vector<string> messages;
public:
	MessageCard(int x,int y,int fontSize,int textCol,int bgCol);
	void init()override {};
	int addPage(string msc);
	void nextPage();
	void prevPage();
	void jumpTo(int page);
	int nowPage();
	bool isEnd();

	void update()override {};
	void draw()override;
	
};

