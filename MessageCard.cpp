#include "MessageCard.h"
#include"DxLib.h"
#pragma warning(disable:4018)


MessageCard::MessageCard(int x, int y, int fontSize, int textCol, int bgCol)
{
	this->x = x;
	this->y = y;
	this->bgCol = bgCol;
	this->textCol = textCol;
	font = CreateFontToHandle("ƒƒCƒŠƒI", fontSize, 4, DX_FONTTYPE_ANTIALIASING);
}

int MessageCard::addPage(string msc)
{
	messages.push_back(msc);
	jumpTo(0);
	return messages.size() - 1;
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
	GetDrawStringSizeToHandle(&xText, &yText,NULL,messages[pageIndex].c_str(),messages[pageIndex].length(),font);
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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawBox(x, y,
		x+xMargin * 2 + xText,
		y+yMargin * 2 + yText, 
		bgCol, TRUE);
	DrawFormatStringToHandle(x + xMargin, y + yMargin,
		textCol, font, messages[pageIndex].c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
