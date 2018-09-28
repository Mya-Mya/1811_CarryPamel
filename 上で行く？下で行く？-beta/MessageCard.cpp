#include "MessageCard.h"
#include"DxLib.h"

MessageCard::MessageCard(int x, int y)
{
	this->x = x;
	this->y = y;
	smallFont = CreateFontToHandle("ƒƒCƒŠƒI", 20, 4, DX_FONTTYPE_NORMAL);
}

void MessageCard::add(string message)
{
	messages.push_back(message);
	jumpTo(0);
}

void MessageCard::nextPage()
{
	jumpTo(pageIndex + 1);
}

void MessageCard::prevPage()
{
	jumpTo(pageIndex - 1);
}

void MessageCard::jumpTo(int page)
{
	if (page < 0 || messages.size() < page)return;
	pageIndex = page;
	if (isEnd())return;
	//GetDrawStringSizeToHandle(&xText, &yText, NULL, smallFont, messages[pageIndex].c_str());
	GetDrawStringSizeToHandle(&xText, &yText,NULL,messages[pageIndex].c_str(),messages[pageIndex].length(),smallFont);
}

int MessageCard::nowPage()
{
	return pageIndex;
}

bool MessageCard::isEnd()
{
	return messages.size()==pageIndex;
}


void MessageCard::draw()
{
	if (isEnd())return;

	DrawBox(x, y,
		x+xMargin * 2 + xText,
		y+yMargin * 2 + yText, 
		GetColor(40, 40, 40), TRUE);
	DrawFormatStringToHandle(x + xMargin, y + yMargin,
		GetColor(240, 240, 240), smallFont, messages[pageIndex].c_str());
}
