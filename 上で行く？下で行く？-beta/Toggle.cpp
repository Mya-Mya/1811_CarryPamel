#include "Toggle.h"
#include"DxLib.h"
#include"Singleton.h"
#pragma warning(disable:4244)

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

	setText(text);

	availableTextCol = GetColor(243, 100, 17);
	unavailableTextCol = GetColor(120, 120, 120);
	availableBgCol = GetColor(255, 255, 255);
	unavailableBgCol = GetColor(150,150,150);
}

void Toggle::setText(string text)
{
	this->text = text;
	int textW, textH;
	GetDrawStringSizeToHandle(&textW, &textH, NULL, text.c_str(), text.length(), font);

	this->textX = x + w * 0.5 - textW * 0.5;
	this->textY = y + h * 0.5 - textH * 0.5 /*お気持ちで10下へやってる*/+10;
}

void Toggle::setAvailable(bool available)
{
	this->available = available;
}

void Toggle::update()
{
	//有効な状態に定められたキーが押されたらハンドラーに働きかける
	if (available&&Keyboard::Instance()->Get(casingKeyNum) ==1)eventFire();
}

void Toggle::draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(x, y, x + w, y + h,
		available ? availableBgCol : unavailableBgCol
		, TRUE);
	DrawBox(x, y, x + w, y + h,
		available ? availableTextCol : unavailableTextCol
		, FALSE);
	DrawFormatStringToHandle(textX, textY, 
		available?availableTextCol:unavailableTextCol
		, font, text.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
