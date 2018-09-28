#include "Toggle.h"
#include"DxLib.h"
#include"Singleton.h"

Toggle::Toggle(int x, int y, int w, int h, string text, int textsize,int casingKeyNum)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->textsize = textsize;
	this->casingKeyNum = casingKeyNum;

	font = CreateFontToHandle("メイリオ", textsize, 4, DX_FONTTYPE_NORMAL);
	int textW = GetDrawFormatStringWidthToHandle(font, text.c_str());

	this->textX = x + w * 0.5 - textW * 0.5;
	this->textY = y + h * 0.5 - textsize * 0.5;

	availableCol = GetColor(238, 247, 79);
	unavailableCol = GetColor(183, 186, 135);
}

void Toggle::setAvailable(bool available)
{
	this->available = available;
	if (available)nowCol = availableCol;
	if (!available)nowCol = unavailableCol;
}

void Toggle::update()
{
	//有効な状態に定められたキーが押されたらハンドラーに働きかける
	if (available&&Keyboard::Instance()->Get(casingKeyNum) != 0)eventFire();
}

void Toggle::draw()
{
	DrawBox(x, y, x + w, y + h, nowCol, FALSE);
	DrawFormatStringToHandle(textX, textY, nowCol, font, text.c_str());
}
