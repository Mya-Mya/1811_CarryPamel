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

	int smallFont;
	int pageIndex=0;
	vector<string> messages;
public:
	MessageCard(int x,int y);
	void init()override {};
	void add(string message);
	void nextPage();
	void prevPage();
	void jumpTo(int page);
	int nowPage();
	bool isEnd();

	void update()override {};
	void draw()override;
	
};

